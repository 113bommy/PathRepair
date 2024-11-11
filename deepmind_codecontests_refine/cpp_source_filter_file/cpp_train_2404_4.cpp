#include <bits/stdc++.h>
using namespace std;
const long long int huge = 1e17;
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int abbs(long long int a, long long int b) {
  if (a - b < 0) return b - a;
  return a - b;
}
long long int lowerB(vector<long long int> &v, long long int val) {
  long long int ind = v.size(), l = 0, r = v.size(), mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (v[mid] >= val) {
      ind = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ind;
}
long long int n, m, k, mid;
map<long long int, long long int> mp[50][50];
long long int ans;
long long int v[50][50];
void rb(long long int r, long long int c, long long int xr, long long int cnt) {
  xr ^= v[r][c];
  mp[r][c][xr]++;
  if (cnt == mid) {
    return;
  }
  if (r + 1 < n) rb(r + 1, c, xr, cnt + 1);
  if (c + 1 < m) rb(r, c + 1, xr, cnt + 1);
}
void tl(long long int r, long long int c, long long int xr, long long int cnt) {
  if (cnt - 1 == (n + m - 2 - mid)) {
    ans += mp[r][c][xr ^ k];
    return;
  }
  xr ^= v[r][c];
  mp[r][c][xr]++;
  if (r >= 1) tl(r - 1, c, xr, cnt + 1);
  if (c >= 1) tl(r, c - 1, xr, cnt + 1);
}
void solve() {
  cin >> n >> m >> k;
  for (long long int i = 0; i < n; i++)
    for (long long int j = 0; j < m; j++) cin >> v[i][j];
  mid = (n + m - 2) / 2;
  rb(0, 0, 0, 0);
  tl(n - 1, m - 1, 0, 0);
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
}
