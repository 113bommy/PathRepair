#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 9, INF = 1e9, M = 1e5 + 9;
int n, k, a[N], b[N], mem[N][M];
map<pair<int, int>, int> mp;
int solve(int idx = 0, int sum1 = 0) {
  if (idx == n) {
    if (!sum1) return 0;
    return -10000;
  }
  int &ret = mem[idx][sum1];
  if (~ret) return ret;
  int c1 = solve(idx + 1, sum1);
  int c2 = solve(idx + 1, sum1 + (a[idx] - b[idx])) + a[idx];
  return ret = max(c1, c2);
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < n; ++i) b[i] *= k;
  memset(mem, -1, sizeof(mem));
  int ans = solve();
  if (ans <= 0)
    cout << -1;
  else
    cout << ans;
  return 0;
}
