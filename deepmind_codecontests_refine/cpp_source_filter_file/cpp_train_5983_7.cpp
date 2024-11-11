#include <bits/stdc++.h>
using namespace std;
int mini(int a, int b) { return a < b ? a : b; }
int main() {
  int n, m;
  cin >> n >> m;
  m--;
  string s;
  cin >> s;
  int c = 0, i, j, f = -1, l = -1;
  for (i = 0; i < n / 2; i++) {
    int g = abs(s[i] - s[n - i - 1]);
    c += mini(g, 26 - g);
    if (g) {
      if (f == -1) f = i;
      l = i;
    }
  }
  if (!c) {
    cout << "0" << endl;
    return 0;
  }
  if (!(n & 1) && m == n / 2)
    m = 0;
  else if (m > n / 2) {
    m = n - 1 - m;
  }
  if (m >= l)
    c += (m - f);
  else if (m <= f)
    c += (l - m);
  else
    c += (mini(l - m, m - f) + l - f);
  cout << c << endl;
  return 0;
}
