#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void wrote(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) wrote(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(int x) {
  wrote(x);
  puts("");
}
const int N = 5010;
map<string, int> mp;
string s;
int answ[N][2], L[N], R[N], a[5010][1010], ans[N][2], typ[N], n, m;
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    mp[s] = i;
    cin >> s;
    cin >> s;
    if (s[0] == '0' || s[0] == '1') {
      typ[i] = 1;
      for (int j = 0; j <= m - 1; ++j) a[i][j] = s[j] - '0';
      continue;
    }
    if (s[0] == '?')
      L[i] = 0;
    else
      L[i] = mp[s];
    cin >> s;
    if (s[0] == 'X')
      typ[i] = 2;
    else if (s[0] == 'O')
      typ[i] = 3;
    else if (s[0] == 'A')
      typ[i] = 4;
    cin >> s;
    if (s[0] == '?')
      R[i] = 0;
    else
      R[i] = mp[s];
  }
  for (int i = 0; i <= m - 1; ++i) {
    memset(ans, 0, sizeof ans);
    for (int k = 1; k <= n; ++k)
      if (typ[k] == 1)
        ans[k][0] = ans[k][1] = a[k][i];
      else {
        int x0 = 0, y0 = 0, x1 = 0, y1 = 0;
        if (L[k])
          x0 += ans[L[k]][0], x1 += ans[L[k]][0];
        else
          x1 = 1;
        if (R[k])
          y0 += ans[R[k]][0], y1 += ans[R[k]][1];
        else
          y1 = 1;
        if (typ[k] == 2) ans[k][0] = x0 ^ y0, ans[k][1] = x1 ^ y1;
        if (typ[k] == 3) ans[k][0] = x0 | y0, ans[k][1] = x1 | y1;
        if (typ[k] == 4) ans[k][0] = x0 & y0, ans[k][1] = x1 & y1;
      }
    int zero = 0, one = 0;
    for (int k = 1; k <= n; ++k) zero += ans[k][0], one += ans[k][1];
    answ[i][0] = zero > one;
    answ[i][1] = zero < one;
  }
  for (int i = 0; i <= m - 1; ++i) putchar(answ[i][0] + '0');
  puts("");
  for (int i = 0; i <= m - 1; ++i) putchar(answ[i][1] + '0');
}
