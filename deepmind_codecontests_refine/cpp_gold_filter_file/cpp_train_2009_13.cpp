#include <bits/stdc++.h>
using namespace std;
string s, s2, s4, s7, b, c;
string d, e, g;
int a1, a2, a3, a4, flag, n, dem4, dem7, k, z, m, flag2;
int main() {
  cin >> a1 >> a2 >> a3 >> a4;
  for (int i = 1; i <= a3; i++) {
    s += 52;
    s += 55;
  }
  if (a4 == a3 && a1 != a3) {
    s += 52;
    flag2 = 1;
  }
  if (a4 == a3 && flag2 == 0) {
    g += 55;
    s = g + s;
  }
  if (a4 == a3 + 1) {
    s += 52;
    s2 += 55;
    s = s2 + s;
  }
  if (a4 < a3 - 1) flag = 1;
  if (a4 > a3 + 1) flag = 1;
  n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] - 48 == 4) dem4++;
    if (s[i] - 48 == 7) dem7++;
  }
  if (dem7 > a2 || dem4 > a1)
    flag = 1;
  else {
    for (int i = 1; i <= a1 - dem4; i++) s4 += 52;
    for (int i = 1; i <= a2 - dem7; i++) s7 += 55;
    for (int i = 0; i < n; i++)
      if (s[i] - 48 == 4) {
        k = i;
        break;
      }
    for (int i = 0; i < k; i++) b += s[i];
    for (int i = k; i < n; i++) c += s[i];
    b += s4;
    b += c;
    m = b.size();
    for (int i = m - 1; i >= 0; i--)
      if (b[i] - 48 == 7) {
        z = i;
        break;
      }
    for (int i = 0; i < z; i++) d += b[i];
    for (int i = z; i < m; i++) e += b[i];
    d += s7;
    d += e;
  }
  if (flag == 1)
    printf("-1");
  else
    cout << d;
}
