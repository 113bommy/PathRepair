#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int ltree[500001], rtree[500001];
void update(int *tree, int n, int v) {
  for (; n <= 500000; n += n & -n) tree[n] = (tree[n] + v) % MOD;
}
int get_cnt(int *tree, int n) {
  int ret = 0;
  for (; n; n -= n & -n) ret = (ret + tree[n]) % MOD;
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ((void)0);
  ((void)0);
  ((void)0);
  int N, ans = 0;
  priority_queue<pair<int, int>> Q;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    Q.push({-a, i});
  }
  while (!Q.empty()) {
    auto [a, idx] = Q.top();
    Q.pop();
    update(ltree, idx, idx);
    ans = (ans - 1LL * a *
                     ((1LL * (N + 1 - idx) * get_cnt(ltree, idx) +
                       1LL * idx * get_cnt(rtree, idx)) %
                      MOD)) %
          MOD;
    update(rtree, 1, N + 1 - idx);
    update(rtree, idx + 1, -N - 1 + idx);
  }
  cout << ans << '\n';
  return 0;
}
