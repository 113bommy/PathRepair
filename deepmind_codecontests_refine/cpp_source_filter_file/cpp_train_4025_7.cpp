#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int MOD = 1000000007;
const long long INFLL = 1e18;
const long double PI = 2 * acos(0.0);
int calc(int a, int b) {
  int x = b / a;
  while (a - x * b > 0) ++x;
  return x;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string a, b;
  cin >> a >> b;
  int h, d, c, n;
  cin >> h >> d;
  cin >> c >> n;
  long double res;
  if (stoi(a) >= 20)
    res = (long double)calc(h, n) * (long double)c * 0.2;
  else {
    res = (long double)calc(h, n) * (long double)c;
    int m = 60 - stoi(b) + (20 - stoi(a) - 1) * 60;
    res = min(res, (long double)calc(h + m * d, n) * (long double)c * 0.8);
  }
  cout << fixed << setprecision(12) << res << endl;
  return 0;
}
