#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const double eps = 1e-5;
const int maxN = 10000;
const int maxL = 20;
const int inf = 1e9;
int n;
int sz;
int a[maxN];
int ans;
inline int dfs(int v) {
  int l = (v * 2), r = (v * 2 + 1);
  if (l > sz) return 0;
  int r1 = a[l] + dfs(l), r2 = a[r] + dfs(r);
  ans += abs(r1 - r2);
  return (max(r1, r2));
}
inline void init() {
  cin >> n;
  sz = (1 << (n + 1)) - 1;
  int sum = 0;
  for (int i = 2; i <= sz; i++) cin >> a[i], sum += a[i];
  dfs(1);
  cout << ans << endl;
}
inline void solve() {}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  init();
  solve();
  return 0;
}
