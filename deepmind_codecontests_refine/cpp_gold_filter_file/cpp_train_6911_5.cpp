#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  bool b = 0;
  char c;
  while (!isdigit(c = getchar()) && c != '-')
    ;
  if (c == '-') c = getchar(), b = 1;
  x = c - 48;
  while (isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - 48;
  if (b) x = -x;
}
template <typename T>
inline void wrip(T x) {
  if (x > 9) wrip(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  wrip(x);
  putchar(' ');
}
template <typename T>
inline void writeln(T x) {
  if (x < 0) putchar('-'), x = -x;
  wrip(x);
  putchar('\n');
}
inline char readch() {
  char c;
  do c = getchar();
  while (c == '\n' || c == ' ');
  return c;
}
inline void reads(string &s) {
  char c;
  while ((c = getchar()) == ' ' || c == '\n')
    ;
  s = c;
  while ((c = getchar()) != ' ' && c != '\n') s += c;
}
inline void getlines(string &s) {
  char c;
  while ((c = getchar()) == '\n')
    ;
  s = c;
  while ((c = getchar()) != '\n') s += c;
}
const long double pi = acos(-1);
const long double eps = 1e-9;
const int inf = 1e9, mod = 1e9 + 7, N = 2011;
int n, m, res;
int a[N], b[N];
long long pw[N];
int main() {
  read(n);
  read(m);
  for (int i = 1, x = 0; i <= n; i++) {
    read(x);
    for (int j = 0; j <= 29; j++)
      if (x >> j & 1) a[j]++;
  }
  for (int i = 1, x = 0; i <= m; i++) {
    read(x);
    b[x]++;
  }
  pw[0] = 1;
  for (int i = 1; i <= 29; i++) pw[i] = pw[i - 1] * 2;
  for (int i = 0; i <= 29; i++) {
    long long num = 0;
    for (int j = i; j <= 29; j++) {
      if (num + pw[j - i] * a[j] >= b[i]) {
        int need = (b[i] - num - 1) / pw[j - i] + 1;
        int rem = pw[j - i] * need - (b[i] - num);
        a[j] -= need;
        for (int k = 1; k + i <= 29; k++) a[k + i] += (rem >> k & 1);
        num = b[i];
        break;
      }
      num += pw[j - i] * a[j];
      a[j] = 0;
    }
    res += num;
  }
  cout << res;
}
