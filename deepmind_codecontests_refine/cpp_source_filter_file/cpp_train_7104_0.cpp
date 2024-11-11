#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long o1, o2, o3;
  string tjk = "";
  cin >> o1 >> o2 >> o3;
  if (!o1 && !o2) o3++;
  if (!o1 && o3) o1--;
  for (int i = 0; i <= o1; ++i) tjk += '0';
  for (int i = 1; i <= o2; ++i) {
    if (i == o2 && o2 % 2 == 0) {
      tjk = '1' + tjk;
      break;
    }
    tjk += '0' + (i % 2);
  }
  while (o3--) tjk += '1';
  cout << tjk;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
    cout << '\n';
  }
  cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
