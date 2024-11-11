#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline long long llread() {
  char ch = getchar();
  long long x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct Node {
  int a, b, c;
} E[20][110];
struct Edge {
  int u, v;
  inline bool operator<(const Edge& rhs) const { return u > rhs.u; }
} a[110];
int main() {
  int n = read(), m = read(), k = read();
  string s;
  for (int i = (1); i <= (n); i++) {
    cin >> s;
    for (int j = (1); j <= (m); j++) {
      E[i][j] = (Node){read(), read(), read()};
    }
  }
  int ans = 0;
  for (int i1 = (1); i1 <= (n); i1++)
    for (int i2 = (1); i2 <= (n); i2++)
      if (i1 != i2) {
        for (int i = (1); i <= (m); i++) {
          a[i].u = E[i2][i].b - E[i1][i].a;
          a[i].v = E[i1][i].c;
        }
        sort(a + 1, a + m + 1);
        int kk = k, res = 0;
        for (int i = (1); i <= (m); i++) {
          int us = min(kk, a[i].v);
          if (a[i].u <= 0) break;
          res += a[i].u * us;
          kk -= us;
          if (!kk) break;
        }
        ans = max(ans, res);
      }
  printf("%d\n", ans);
  return 0;
}
