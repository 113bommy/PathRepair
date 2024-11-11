#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long MAX = 2e6 + 7;
const long long dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const long long dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
long long i, j, k, t, n, q, l, r, mid;
string s;
long long up, dn, rt, lt, ud, rl;
void solve() {
  cin >> s;
  n = s.length();
  up = dn = rt = lt = ud = rl = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'U') up++;
    if (s[i] == 'D') dn++;
    if (s[i] == 'R') rt++;
    if (s[i] == 'L') lt++;
  }
  rl = min(rt, lt);
  ud = min(up, dn);
  if (rl == 0 && ud > 2) ud = 1;
  if (ud == 0 && rl > 2) rl = 1;
  cout << 2 * rl + 2 * ud << endl;
  for (long long i = 0; i < rl; i++) cout << 'R';
  for (long long i = 0; i < ud; i++) cout << 'U';
  for (long long i = 0; i < rl; i++) cout << 'L';
  for (long long i = 0; i < ud; i++) cout << 'D';
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> t;
  while (t--) solve();
  return 0;
}
