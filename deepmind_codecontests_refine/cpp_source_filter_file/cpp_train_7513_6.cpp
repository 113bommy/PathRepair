#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x);
template <typename T>
void write(T x);
template <typename T>
void writesp(T x);
template <typename T>
void writeln(T x);
const int N = 1e6 + 6;
int n, m;
string s[N];
int cnt[N];
vector<bool> f[N], g[N];
int main() {
  read(n);
  read(m);
  for (register int i = 0; i < n; i++)
    f[i] = vector<bool>(m + 1), g[i] = vector<bool>(m + 1);
  f[0][0] = g[n - 1][m - 1] = true;
  for (register int i = 0; i < n; i++) cin >> s[i];
  for (register int i = 0; i < n; i++)
    for (register int j = 0; j < m; j++) {
      if (s[i][j] == '#') continue;
      if (j - 1 >= 0 && s[i][j - 1] == '.') f[i][j] = (f[i][j] | f[i][j - 1]);
      if (i - 1 >= 0 && s[i - 1][j] == '.') f[i][j] = (f[i][j] | f[i - 1][j]);
    }
  for (register int i = n - 1; ~i; i--)
    for (register int j = m - 1; ~j; j--) {
      if (s[i][j] == '#') continue;
      if (j + 1 < m && s[i][j + 1] == '.') g[i][j] = (g[i][j] | g[i][j + 1]);
      if (i + 1 < m && s[i + 1][j] == '.') g[i][j] = (g[i][j] | g[i + 1][j]);
    }
  for (register int i = 0; i < n; i++)
    for (register int j = 0; j < m; j++)
      if (f[i][j] && g[i][j]) ++cnt[i + j];
  for (register int i = 1; i < n + m - 2; i++)
    if (cnt[i] <= 1) return writeln(cnt[i]), 0;
  writeln(2);
}
template <typename T>
void read(T &x) {
  x = 0;
  int t = 1;
  char wn = getchar();
  while (wn < '0' || wn > '9') {
    if (wn == '-') t = -1;
    wn = getchar();
  }
  while (wn >= '0' && wn <= '9') {
    x = x * 10 + wn - '0';
    wn = getchar();
  }
  x *= t;
}
template <typename T>
void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x <= 9) {
    putchar(x + '0');
    return;
  }
  write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void writesp(T x) {
  write(x);
  putchar(' ');
}
template <typename T>
void writeln(T x) {
  write(x);
  putchar('\n');
}
