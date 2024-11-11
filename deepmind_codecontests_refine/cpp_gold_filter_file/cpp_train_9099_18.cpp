#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, T, opt, M, Q;
int a[7010][4], b[7010][2];
int l[120010], r[120010], vis[1000010];
char ch;
inline void read(int &x) {
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    ;
  for (x = 0; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - 48;
}
void Run() {
  int x = 1, y, ans;
  for (int i = 1; i <= 120000; ++i) {
    l[i] = ++cnt;
    if (i == x) ++cnt, x <<= 1;
    r[i] = cnt;
  }
  read(n);
  read(m);
  while (m--) {
    read(opt);
    if (opt == 1)
      ++M, read(a[M][0]), read(a[M][1]), read(a[M][2]), read(a[M][3]);
    else {
      ++Q;
      read(x);
      read(y);
      b[x][0] = b[x][1] = y;
      for (int i = x + 1; i <= n; ++i)
        b[i][0] = l[b[i - 1][0]], b[i][1] = r[b[i - 1][1]];
      ++T;
      ans = 0;
      for (int i = 1; i <= M; ++i) {
        if (a[i][0] >= x &&
            !(b[a[i][0]][0] > a[i][2] || b[a[i][0]][1] < a[i][1]) &&
            vis[a[i][3]] != T) {
          vis[a[i][3]] = T;
          ++ans;
        }
      }
      printf("%d\n", ans);
    }
  }
}
int main() {
  Run();
  return 0;
}
