#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, 100000, stdin);
    if (p1 == p2) return EOF;
  }
  return *p1++;
}
inline void read(int &x) {
  char c = nc(), b = 1;
  for (; !(c >= '0' && c <= '9'); c = nc())
    if (c == '-') b = -1;
  for (x = 0; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = nc())
    ;
  x *= b;
}
const int N = 100005;
int n, m, T;
int u[N], v[N];
int lst[N][25], belong[N];
int c[1000005];
inline bool work() {
  for (int i = 1; i <= n; i++) belong[i] = lst[i][rand() % lst[i][0] + 1];
  for (int i = 1; i <= T; i++) c[i] = (rand() & 1) + 1;
  int ret = 0;
  for (int i = 1; i <= m; i++) ret += c[belong[u[i]]] != c[belong[v[i]]];
  return ret * 2 >= m;
}
int main() {
  srand(10086);
  read(n);
  read(m);
  for (int i = 1; i <= m; i++) read(u[i]), read(v[i]);
  for (int i = 1; i <= n; i++) {
    read(lst[i][0]);
    for (int j = 1; j <= *lst[i]; j++) read(lst[i][j]), T = max(T, lst[i][j]);
  }
  while (!work())
    ;
  for (int i = 1; i <= n; i++) printf("%d ", belong[i]);
  printf("\n");
  for (int i = 1; i <= T; i++) printf("%d ", c[i]);
  printf("\n");
  return 0;
}
