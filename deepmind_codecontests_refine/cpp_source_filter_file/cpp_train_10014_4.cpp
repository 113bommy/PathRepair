#include <bits/stdc++.h>
using namespace std;
using LL = long long;
template <typename T, typename Comp>
class RMQ {
 private:
  const T DEF;
  vector<T> seg;
  int width;
  T query_raw(int a, int b, int k, int l, int r) const {
    if (a >= r || b <= l) return DEF;
    if (a <= l && r <= b) return seg[k];
    return min(query_raw(a, b, 2 * k + 1, l, (l + r) / 2),
               query_raw(a, b, 2 * k + 2, (l + r) / 2, r), Comp());
  }

 public:
  RMQ(int n, T def) : DEF(def) {
    width = 1;
    while (width < n) width *= 2;
    seg.assign(width * 2 - 1, DEF);
  }
  T query(int a, int b) const { return query_raw(a, b, 0, 0, width); }
  void update(int k, T x) {
    k += width - 1;
    seg[k] = x;
    while (k > 0) {
      k = (k - 1) / 2;
      seg[k] = min(seg[2 * k + 1], seg[2 * k + 2], Comp());
    }
  }
  void init(const vector<T>& vec) {
    for (int i = 0; i < min(width, (int)vec.size()); ++i)
      seg[i + width - 1] = vec[i];
    for (int k = width - 2; k >= 0; --k)
      seg[k] = min(seg[2 * k + 1], seg[2 * k + 2], Comp());
  }
};
int N;
int main() {
  cin >> N;
  vector<LL> A, B(3 * N);
  set<LL> S;
  for (int i = 0; i < N; ++i) {
    LL elm;
    cin >> elm;
    A.push_back(elm);
    S.insert(elm);
  }
  for (int i = 0; i < N; ++i) A.push_back(A[i]);
  for (int i = 0; i < N; ++i) A.push_back(A[i]);
  vector<LL> dic;
  map<LL, int> inv;
  for (LL s : S) dic.push_back(s);
  int M = dic.size();
  for (int i = 0; i < M; ++i) {
    inv[dic[i]] = i;
  }
  RMQ<LL, less<LL>> tree(M, 12345678901234LL);
  int poke = N + N;
  while (A[poke] != dic.back()) --poke;
  int ans = -1;
  for (int p = poke; p < poke + N; ++p) {
    if (A[p] * 2 < A[poke]) {
      ans = p;
      break;
    }
  }
  if (ans == -1) {
    for (int i = 0; i < N; ++i) {
      cout << -1 << " \n"[i == N - 1];
    }
    return 0;
  }
  B[poke] = ans;
  for (int p = poke; p < poke + N; ++p) {
    tree.update(inv[A[p]], p);
  }
  for (int x = poke - 1; x >= 0; --x) {
    int L = lower_bound(dic.begin(), dic.end(), A[x]) - dic.begin();
    LL bigger = tree.query(L, M);
    int R = upper_bound(dic.begin(), dic.end(), A[x] / 2) - dic.begin();
    LL halfer = tree.query(0, R);
    if (bigger < halfer) {
      B[x] = B[bigger];
    } else {
      B[x] = halfer;
    }
    tree.update(inv[A[x]], x);
  }
  for (int i = 0; i < N; ++i) {
    cout << B[i] - i << " \n"[i == N - 1];
  }
  return 0;
}
