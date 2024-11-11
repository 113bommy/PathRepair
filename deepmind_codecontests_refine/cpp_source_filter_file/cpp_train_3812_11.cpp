#include <bits/stdc++.h>
using namespace std;
const int MAXB = 1e5;
char buf[MAXB], *cp = buf;
inline void rd(int &x) {
  x = 0;
  int f = 1;
  while (*cp < '0' || '9' < *cp) {
    if (*cp == '-') f = -1;
    cp++;
  }
  while ('0' <= *cp && *cp <= '9') x = (x << 3) + (x << 1) + *cp - 48, cp++;
  x *= f;
}
const int MAXN = 1010;
int n, cnt;
int t[MAXN][5], ans[MAXN];
int main() {
  fread(buf, 1, MAXB, stdin);
  rd(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 5; j++) rd(t[i][j]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (j != i)
        for (int k = j + 1; k < n; k++)
          if (k != i) {
            int tmp = 0;
            for (int l = 0; l < 5; l++)
              tmp += (t[j][l] - t[i][l]) * (t[k][l] * t[i][l]);
            if (tmp > 0) goto nxt;
          }
    ans[cnt++] = i;
  nxt:;
  }
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++) printf("%d ", ans[i] + 1);
  printf("\n");
  return 0;
}
