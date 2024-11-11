#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010, maxall = 1LL << 15, oo = ~0U >> 3;
int n, m, all, ans, res;
string st[20];
int nex[maxn][20];
int F[maxall][120];
int num[20];
int val[maxn];
string sz;
void up(int &a, int b) {
  if (a > b) a = b;
}
void solve(int T) {
  int i, j, k, one;
  scanf("%d", &m);
  for (i = 1; i <= m; ++i) {
    cin >> sz;
    for (val[i] = -1, j = 0; j < n; ++j)
      if (sz == st[j]) val[i] = j;
  }
  memset(num, 127, sizeof(num));
  for (i = m; i >= 0; --i) {
    for (j = 0; j < n; ++j) nex[i][j] = num[j];
    if (val[i] != -1) num[val[i]] = i;
  }
  memset(F, 127, sizeof(F));
  F[0][0] = 0;
  for (i = 0; i < (1 << n) - 1; ++i)
    for (j = 0; j <= all; ++j)
      if (F[i][j] < oo)
        for (one = 0, k = n - 1; k >= 0; --k)
          if ((i & (1 << k)) == 0)
            up(F[i | (1 << k)][j + one], nex[F[i][j]][k]);
          else
            ++one;
  for (i = 0; i <= all; ++i)
    if (F[(1 << n) - 1][i] <= m) break;
  if (i < ans) ans = i, res = T;
}
int main() {
  int i, T;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) cin >> st[i];
  all = n * (n - 1) / 2;
  scanf("%d", &T);
  ans = all + 1;
  for (i = 1; i <= T; ++i) solve(i);
  if (res) {
    printf("%d\n", res);
    printf("[:");
    for (i = 1; i <= all - ans + 1; ++i) printf("|");
    printf(":]");
  } else
    printf("Brand new problem!");
  return 0;
}
