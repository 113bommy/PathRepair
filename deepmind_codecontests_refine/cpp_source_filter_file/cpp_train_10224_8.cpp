#include <bits/stdc++.h>
using namespace std;
const int SZ = 1 << 18;
vector<pair<int, int>> V;
vector<tuple<int, int, int>> Q;
int tree[2 * SZ], ans[100000], A[100000];
void add_tree(int n, int v) {
  for (tree[n += SZ] += v; n >>= 1;) tree[n] = tree[2 * n] + tree[2 * n + 1];
}
int kth(int k) {
  int bit = 1, s = 0, e = SZ - 1;
  while (s < e) {
    int m = (s + e) >> 1;
    if (tree[2 * bit] >= k) {
      bit = 2 * bit;
      e = m;
    } else {
      k -= tree[2 * bit];
      bit = 2 * bit + 1;
      s = m + 1;
    }
  }
  return s;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ((void)0);
  ((void)0);
  ((void)0);
  int N, M, j = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    V.emplace_back(A[i], i);
  }
  sort(V.begin(), V.end(), [](pair<int, int> a, pair<int, int> b) {
    return a.first == b.first ? a.second < b.second : a.first > b.first;
  });
  cin >> M;
  for (int i = 0; i < M; i++) {
    int k, p;
    cin >> k >> p;
    Q.emplace_back(--k, p, i);
  }
  sort(Q.begin(), Q.end());
  for (int i = 0; i < N; i++) {
    add_tree(V[i].second, 1);
    while (j < M && get<0>(Q[j]) == i) {
      auto [k, p, idx] = Q[j++];
      ans[idx] = A[kth(p)];
    }
  }
  for (int i = 0; i < M; i++) cout << ans[i] << '\n';
  return 0;
}
