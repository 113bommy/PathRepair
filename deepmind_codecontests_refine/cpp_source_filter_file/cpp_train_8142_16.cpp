#include <bits/stdc++.h>
using namespace std;
char buf[1 << 15], *fs, *ft;
inline char getc() {
  return (fs == ft &&
          (ft = (fs = buf) + fread(buf, 1, 1 << 15, stdin), fs == ft))
             ? 0
             : *fs++;
}
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
const int MAXN = 200010;
int n;
char a[MAXN];
long long ha[MAXN][2], w[MAXN], p[MAXN];
inline int get(int l, int r) {
  return ((ha[r][l & 1] - ha[l - 1][l & 1] * p[w[r] - w[l - 1]]) % 998244353 +
          998244353) %
         998244353;
}
int main() {
  n = read();
  scanf("%s", a + 1);
  p[0] = 1;
  for (int i = 1; i <= n; ++i) {
    w[i] = w[i - 1];
    p[i] = p[i - 1] * 13331ll % 998244353;
    ha[i][0] = ha[i - 1][0];
    ha[i][1] = ha[i - 1][1];
    if (a[i] != '0') continue;
    ha[i][0] = ha[i][0] * 13331ll + 1 % 998244353;
    ha[i][1] = ha[i][1] * 13331ll + 1 % 998244353;
    if (i & 1)
      ha[i][1] = ha[i][1] + 1;
    else
      ha[i][0] = ha[i][0] + 1;
    ++w[i];
  }
  n = read();
  for (int i = 1; i <= n; ++i) {
    int l, r, L, R, len;
    l = read();
    L = read();
    len = read();
    r = l + len - 1;
    R = L + len - 1;
    if (get(l, r) == get(L, R))
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
