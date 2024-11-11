#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int logn = 20;
const int inf = (int)1e9;
const long long mod = (int)1e9 + 7;
const long long l_inf = (long long)4e18;
const long double pi = acosl(-1.0);
const long double eps = 1e-9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(15);
  cout << fixed;
  int a, b, x, y, k = 1;
  int f[510][510];
  cin >> b >> a >> y >> x;
  string s;
  f[x][y] = 1;
  cin >> s;
  cout << "1 ";
  for (int i = 0; i < ((int)s.size()) - 1; i++) {
    if (s[i] == 'R' && y < a) y++;
    if (s[i] == 'L' && y > 1) y--;
    if (s[i] == 'D' && x < b) x++;
    if (s[i] == 'U' && x > 1) x--;
    if (f[x][y] != 1) {
      f[x][y] = 1;
      k++;
      cout << "1 ";
    } else {
      cout << "0 ";
    }
  }
  cout << max(a * b - k, 0);
  return 0;
}
