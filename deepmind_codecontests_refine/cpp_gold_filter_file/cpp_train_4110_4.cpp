#include <bits/stdc++.h>
using namespace std;
const int MX = 2e5 + 5, MXX = 23;
const long long mod = 1e9 + 7, inf = 1e18 + 6;
double cost(double x, double y) { return max(3 * x / 10, x - (x / 250) * y); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(9);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (cost(a, c) > cost(b, d))
    cout << "Misha" << endl;
  else if (cost(a, c) < cost(b, d))
    cout << "Vasya" << endl;
  else
    cout << "Tie" << endl;
  return 0;
}
