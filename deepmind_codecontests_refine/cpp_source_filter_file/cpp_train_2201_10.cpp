#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 1000005;
const double PI = 4 * atan(1);
long long m, x, y, n, p, z, k;
long long h1, m1, h2, m2;
char c, cc;
int main() {
  ios::sync_with_stdio(0);
  cin >> h1 >> c >> m1 >> h2 >> cc >> m2;
  x = (h2 - h1) * 60 + m2 - m1;
  x /= 2;
  x += m1;
  if ((h1 + x / 60) < 10) cout << 0;
  cout << h1 + x / 60 << ":";
  if (((m1 + x) % 60 < 10)) cout << 0;
  cout << x % 60;
  return 0;
}
