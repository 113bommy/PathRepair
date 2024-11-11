#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e9 + 999999;
const long long Mod = (long long)1e9 + 7;
const long long MaXN = (long long)1e18;
const int N = (int)1e6 + 7;
const int MaXI = (int)1e9;
const int Mass = (int)2e5;
long double d, a, b, c;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> a >> b >> c >> d;
  cout << setprecision(6) << fixed;
  cout << (b - a) / (c + d);
  return 0;
}
