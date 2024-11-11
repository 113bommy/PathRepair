#include <bits/stdc++.h>
using namespace std;
inline char ch() {
  static char s[1 << 16], *S, *T;
  return (S == T) && (T = (S = s) + fread(s, 1, 1 << 16, stdin), S == T) ? EOF
                                                                         : *S++;
}
template <typename T>
void read(T &x) {
  x = 0;
  int f(1);
  char c = ch();
  for (; !isdigit(c); c = ch())
    if (c == '-') f = -1;
  for (; isdigit(c); c = ch()) x = x * 10 + c - '0';
  x *= f;
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args) {
  read(x);
  read(args...);
}
const int maxn = 1000005;
int n, m, nxt[maxn];
char S[maxn];
int fg[maxn];
void Get_Nxt() {
  nxt[0] = n;
  int nw = 0;
  while (S[nw] == S[nw + 1] && nw + 1 < n) ++nw;
  nxt[1] = nw;
  int np = 1;
  for (int i(2); i < n; ++i) {
    if (i + nxt[i - np] < np + nxt[np])
      nxt[i] = nxt[i - np];
    else {
      nw = nxt[np] + np - i;
      nw = max(nw, 0);
      while (S[nw] == S[i + nw] && i + nw < n) ++nw;
      nxt[i] = nw;
      np = i;
    }
  }
}
int main() {
  read(n, m);
  for (int i(1); i <= n; ++i) S[i - 1] = ch();
  Get_Nxt();
  nxt[n] = 0x3f3f3f3f;
  for (int i(1); i <= n; ++i) {
    int x = m * i;
    if (x > n) break;
    if (nxt[i] < (m - 1) * i) continue;
    int l = x, r = x + min(nxt[x], i);
    r = min(r, n);
    ++fg[l];
    --fg[r + 1];
  }
  for (int i(1); i <= n; ++i) {
    fg[i] += fg[i - 1];
    if (fg[i] > 0)
      putchar('1');
    else
      putchar('0');
  }
  return 0;
}
