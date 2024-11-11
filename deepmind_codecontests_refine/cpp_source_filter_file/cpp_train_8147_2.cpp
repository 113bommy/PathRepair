#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
using namespace std;
template <class T>
void read(T &x) {
  int f = 0;
  x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  if (f) x = -x;
}
const int N = 1000005;
int L[N], n, m, res = 1e9 + 99;
int qry(int x, int y) {
  printf("? %d %d\n", x, y);
  fflush(stdout);
  int ret;
  read(ret);
  return ret;
}
int main() {
  read(n), read(m);
  L[0] = 1;
  for (int i = (1); i <= (n); i++) {
    L[i] = L[i - 1];
    int ini = qry(i, L[i]);
    int mn = ini;
    for (int j = L[i] + 1; j <= m; j++) {
      int now = qry(i, j);
      if (i >= 2 && now > ini) break;
      if (now < mn) {
        mn = now;
        L[i] = j;
      }
    }
    res = min(res, mn);
  }
  printf("! %d", res);
  fflush(stdout);
  return 0;
}
