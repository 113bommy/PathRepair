#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int n = s.length(), m = t.length();
  for (int i = 0; i < n; i++) s[i] -= '0';
  for (int j = 0; j < m; j++) t[j] -= '0';
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  int i = n - 1;
  while (i >= 0 && s[i] == 0) i--;
  int j = n - 1;
  while (j >= 0 && t[j] == 0) j--;
  if (i >= j + 2) {
    cout << ">\n";
    return 0;
  }
  if (j >= i + 2) {
    cout << "<\n";
    return 0;
  }
  int h = min(i, j);
  int a = 0, c = h + 1 < n ? s[h + 1] : 0;
  int b = 0, d = h + 1 < m ? t[h + 1] : 0;
  while (h >= 0) {
    int x;
    x = min(a, b), a -= x, b -= x;
    x = min(c, d), c -= x, d -= x;
    if (a && d == 0) {
      cout << ">\n";
      return 0;
    }
    if (b && c == 0) {
      cout << "<\n";
      return 0;
    }
    int e = s[h];
    c += a, e += a, a = c, c = e;
    int f = t[h];
    d += b, f += b, b = d, d = f;
    h--;
  }
  double q = (sqrt(5) + 1) / 2;
  double z = (a * q + c) - (b * q + d);
  cout << (z == 0 ? '=' : z < 0 ? '<' : '>') << '\n';
  return 0;
}
