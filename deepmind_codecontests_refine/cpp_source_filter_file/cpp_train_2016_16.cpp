#include <bits/stdc++.h>
using namespace std;
const int N = 50010;
bool f[34][32][N];
int a[N], id[N], cnt;
int res, ans[N];
int n, x, p;
int gao(int x, int y) {
  if (y >= 10) return x * 100 + y;
  return x * 10 + y;
}
int main() {
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (x < 32) a[++cnt] = x, id[cnt] = i;
  }
  for (int i = 1; i <= cnt; i++) {
    f[i][a[i]][a[i] % p] = 1;
    for (int j = 0; j < 32; j++)
      for (int k = 0; k < p; k++)
        if (f[i - 1][j][k]) {
          f[i][j][k] = 1;
          f[i][j ^ a[i]][gao(j, a[i]) % p] = 1;
        }
  }
  if (!f[cnt][0][0]) {
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
  int i = n, j = 0, k = 0;
  for (; i; i--) {
    if (f[i - 1][j][k]) continue;
    ans[++res] = id[i];
    j ^= a[i];
    int flag = 0;
    for (int kk = 0; kk < p; kk++) {
      if (gao(kk, a[i]) % p == k && f[i - 1][j][kk]) {
        flag = 1;
        k = kk;
        break;
      }
    }
    if (!flag) break;
  }
  printf("%d\n", res);
  for (int i = res; i; i--) printf("%d ", ans[i]);
}
