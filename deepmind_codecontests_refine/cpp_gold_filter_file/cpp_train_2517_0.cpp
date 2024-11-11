#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
struct BIT {
  vector<T> dat;
  BIT(int n) : dat(n + 1) {}
  void update(int k, T v) {
    for (int i = k + 1; i < dat.size(); i += i & -i) {
      dat[i] += v;
    }
  }
  T query(int k) {
    T res = 0;
    for (int i = k; i > 0; i -= i & -i) {
      res += dat[i];
    }
    return res;
  }
  T query(int l, int r) { return query(r) - query(l); }
};
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll M, N;
  cin >> M >> N;
  vector<ll> A(N);
  for (int i = 0; i < (N); i++) cin >> A[i];
  vector<ll> B(N);
  for (int i = 0; i < (N); i++) cin >> B[i];
  vector<int> ordA(N), ordB(N);
  for (int i = 0; i < (N); i++) ordA[i] = ordB[i] = i;
  sort(ordA.begin(), ordA.end(), [&](int i, int j) { return A[i] < A[j]; });
  sort(ordB.begin(), ordB.end(), [&](int i, int j) { return B[i] < B[j]; });
  vector<ll> as(N), bs(N * 5);
  for (int i = 0; i < (N); i++) {
    as[i] = A[ordA[i]];
    for (int j = 0; j < (5); j++) {
      bs[i + N * j] = B[ordB[i]] - 2 * M + j * M;
    }
  }
  vector<vector<int>> flipA(N * 5 + 1);
  vector<vector<int>> flipB(N * 5 + 1);
  for (int i = 0; i < (N); i++) {
    int j = upper_bound(bs.begin(), bs.end(), as[i]) - bs.begin();
    flipA[j - i].push_back(i);
  }
  BIT<ll> bit(N * 5);
  for (int i = 0; i < (N * 5); i++) {
    int j = lower_bound(as.begin(), as.end(), bs[i]) - as.begin();
    if (i - j < 0) {
      bit.update(i, bs[i]);
    } else {
      bit.update(i, -bs[i]);
      flipB[i - j].push_back(i);
    }
  }
  pair<ll, int> ans(1e18, -1);
  ll sum_a = 0;
  for (int i = 0; i < (N); i++) sum_a += as[i];
  for (int i = 0; i < N * 4; i++) {
    for (int k : flipA[i]) sum_a -= 2 * as[k];
    ans = min(ans, make_pair(sum_a + bit.query(i, i + N), i));
    for (int k : flipB[i]) bit.update(k, bs[k] * 2);
  }
  cout << ans.first << endl;
  vector<int> output(N);
  for (int i = 0; i < (N); i++) {
    output[ordA[i]] = ordB[(ans.second + i) % N];
  }
  for (int i = 0; i < (N); i++) {
    cout << output[i] + 1 << " \n"[i == N - 1];
  }
}
