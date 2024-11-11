#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const long long INF = 1e18 + 1;
const int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cout << setprecision(10) << fixed;
  int a, b, c;
  cin >> a >> b >> c;
  cout << min(2 * a + 2 * b, min(a + b + c, min(2 * a + c, 2 * b + c)));
  cerr << endl
       << endl
       << "Time execute: " << (float)clock() / CLOCKS_PER_SEC << endl;
  return 0;
}
