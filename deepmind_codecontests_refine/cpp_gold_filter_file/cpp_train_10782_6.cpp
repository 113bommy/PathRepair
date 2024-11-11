#include <bits/stdc++.h>
using namespace std;
long long int a[300000], b[300000];
int main() {
  long long int a1, a2, a3, m, t, c = 0, d = 0, i, s = 0, b1, b2;
  char ch[5];
  cin >> a1 >> a2 >> a3 >> m;
  while (m--) {
    cin >> t >> ch;
    if (ch[0] == 'U')
      a[c++] = t;
    else
      b[d++] = t;
  }
  sort(a, a + c);
  sort(b, b + d);
  b2 = min(a2, d);
  b1 = min(a1, c);
  m = b1 + b2;
  for (i = 0; i < b1; i++) s = s + a[i];
  for (i = 0; i < b2; i++) s = s + b[i];
  while (b1 < c && b2 < d && a3 > 0) {
    if (a[b1] < b[b2])
      s = s + a[b1++];
    else
      s = s + b[b2++];
    m++;
    a3--;
  }
  while (b1 < c && a3 > 0) {
    s = s + a[b1++];
    a3--;
    m++;
  }
  while (b2 < d && a3 > 0) {
    s = s + b[b2++];
    a3--;
    m++;
  }
  cout << m << " " << s;
}
