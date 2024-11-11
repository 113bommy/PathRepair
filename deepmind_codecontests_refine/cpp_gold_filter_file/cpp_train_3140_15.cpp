#include <bits/stdc++.h>
using namespace std;
inline bool muldiv(const char &c) { return c == '*' || c == '/'; }
inline bool addsub(const char &c) { return c == '+' || c == '-'; }
inline bool op(const char &c) { return addsub(c) || muldiv(c); }
const int mod = 1000003;
int d[2222][2222], a[2222], pos[2222], x[2222], y[2222];
int main() {
  string s;
  cin >> s;
  int n = s.size(), m = 0, t = 0;
  for (int i = 1; i < n; i++)
    if (op(s[i - 1]) && muldiv(s[i])) {
      cout << 0 << endl;
      return 0;
    }
  if (muldiv(s[0]) || op(s[n - 1])) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++)
    if (!isdigit(s[i]))
      t++;
    else if (!i || t) {
      a[m++] = t - 1;
      t = 0;
    }
  a[n = 0]++;
  for (int i = 0; i < m; i++) {
    pos[i] = n;
    for (int j = a[i]; j >= 0; j--) {
      x[n] = i;
      y[n++] = j;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    d[i][x[i]] = 1;
    for (int j = x[i] + 1; j < m; j++) {
      if (y[i]) d[i][j] = d[i + 1][j];
      long long add = 0;
      for (int k = x[i]; k < j; k++)
        add += (long long)d[i][k] * d[pos[k + 1]][j];
      d[i][j] = (d[i][j] + add) % mod;
    }
  }
  cout << d[0][m - 1] << endl;
  return 0;
}
