#include <bits/stdc++.h>
using namespace std;
const long long maxN = 2007, MOD = 81409, inf = 1e9, N = 1e4 + 7;
long long a, b, c, d;
int main() {
  cin >> a >> b >> c >> d;
  if (c >= b - 1 && c <= 2 * (b - 1) || d >= a - 1 && d <= 2 * (a - 1))
    return cout << "YES\n", 0;
  return cout << "NO\n", 0;
}
