#include <bits/stdc++.h>
using namespace std;
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool comp(char s1, char s2) { return tolower(s1) < tolower(s2); }
int main() {
  fast();
  int l, r, n, m, a, b, c, i;
  string s;
  cin >> s;
  n = s.length();
  int x[n], y[n], z[n], flag = 0;
  for (i = 0; i < n; i++) {
    x[i] = 0;
    y[i] = 0;
    z[i] = 0;
    if (i != 0) {
      x[i] = x[i - 1];
      y[i] = y[i - 1];
      z[i] = z[i - 1];
    }
    if (s[i] == 'x')
      x[i]++;
    else if (s[i] == 'y')
      y[i]++;
    else
      z[i]++;
  }
  cin >> m;
  while (m--) {
    cin >> l >> r;
    if (r - l < 2)
      cout << "YES" << endl;
    else {
      l--;
      r--;
      a = x[r] - x[l];
      b = y[r] - y[l];
      c = z[r] - z[l];
      if (s[l] == 'x')
        a++;
      else if (s[l] == 'y')
        b++;
      else
        c++;
      if ((a == b && b == c && a == c) || ((b == c && abs(a - b) == 1)) ||
          (a == c && abs(a - b) == 1) || (a == b && abs(b - c) == 1))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
