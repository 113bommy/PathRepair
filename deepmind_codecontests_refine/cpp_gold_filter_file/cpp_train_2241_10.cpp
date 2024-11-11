#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, n, x, y, di, q;
int v[26];
char s[50][101];
int main() {
  cin >> a >> b >> c >> d >> n;
  for (int i = int(0); i < int(n); ++i) cin >> v[i];
  for (int i = int(0); i < int(a + c); ++i)
    for (int j = int(0); j < int(max(b, d)); ++j) s[j][i] = '.';
  x = 0;
  di = 1;
  if (b == 1 || !(a % 2))
    y = 0;
  else {
    y = b - 1;
    di = -1;
  }
  int cnt = a * b + c * d, ch = b;
  for (int p = int(0); p < int(cnt); ++p) {
    s[y][x] = 'a' + q;
    --v[q];
    if (!v[q]) ++q;
    if (y + di >= ch || y + di < 0) {
      di = -di;
      ++x;
      if (x == a) {
        ch = d;
        di = 1;
      }
    } else
      y += di;
  }
  cout << "YES" << endl;
  for (int i = int(0); i < int(max(b, d)); ++i) cout << s[i] << endl;
  return 0;
}
