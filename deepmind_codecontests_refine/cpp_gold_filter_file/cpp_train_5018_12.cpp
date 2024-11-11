#include <bits/stdc++.h>
using namespace std;
clock_t time_p = clock();
void time() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
void solve() {
  long long a, b, r = 0;
  cin >> a >> b;
  a = abs(a - b);
  long long z = a % 5;
  if (z == 1 || z == 2) r = 1;
  if (z == 3 || z == 4) r = 2;
  cout << (a / 5) + r << "\n";
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) solve();
  time();
  return 0;
}
