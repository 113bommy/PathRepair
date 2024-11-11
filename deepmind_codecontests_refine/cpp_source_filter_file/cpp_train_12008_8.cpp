#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
int const N = 5e5 + 10, M = 1e6 + 1, oo = 1e9;
const int mod = oo + 7;
const long long OO = 2e18;
int n, m, x, y, x2, y2;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> x >> y >> x2 >> y2;
  if (abs(x - x2) > 3 && abs(y - y2) > 3)
    cout << "Second\n";
  else if (max(abs(x - x2), abs(y - y2)) > 4)
    cout << "Second\n";
  else if (max(abs(x - x2), abs(y - y2)) == 4 &&
           min(abs(x - x2), abs(y - y2)) == 4)
    cout << "Second\n";
  else
    cout << "First\n";
  return 0;
}
