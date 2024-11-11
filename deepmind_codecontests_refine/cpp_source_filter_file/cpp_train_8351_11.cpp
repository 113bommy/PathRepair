#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}
int readint() {
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
int n;
int tmp[10], k[8], ek[8], d[15][65], f[15][65], g[8][2][65];
long long ans[20000];
char s[15][15];
void dfs(int now, int num) {
  if (now == n + 1) {
    for (int i = 1; i <= n / 2; i++) tmp[i] = i;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < (1 << (n / 2 - 1)); j++) d[i][j] = 0;
    do {
      int str = 0;
      for (int i = 2; i <= n / 2; i++)
        str += (s[k[tmp[i - 1]]][k[tmp[i]]] - '0') << (i - 2);
      d[tmp[n / 2]][str]++;
    } while (next_permutation(tmp + 1, tmp + n / 2 + 1));
    for (int i = 1; i <= n - n / 2; i++) tmp[i] = i;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < (1 << (n - n / 2 - 1)); j++) f[i][j] = 0;
    do {
      int str = 0;
      for (int i = 2; i <= n - n / 2; i++)
        str += (s[ek[tmp[i - 1]]][ek[tmp[i]]] - '0') << (i - 2);
      f[tmp[n - n / 2]][str]++;
    } while (next_permutation(tmp + 1, tmp + n - n / 2 + 1));
    for (int i = 1; i <= n / 2; i++) {
      for (int j = 0; j < (1 << (n - n / 2 - 1)); j++)
        g[i][0][j] = g[i][1][j] = 0;
      for (int j = 1; j <= n - n / 2; j++)
        for (int l = 0; l < (1 << (n - n / 2 - 1)); l++)
          g[i][s[k[i]][ek[j]] - '0'][l] += f[j][l];
    }
    for (int i = 1; i <= n / 2; i++) {
      for (int j = 0; j < (1 << (n / 2 - 1)); j++) {
        for (int l = 0; l < (1 << (n - n / 2 - 1)); l++) {
          ans[(j << (n - n / 2)) + l] += 1ll * g[i][0][l] * d[i][j];
          ans[(j << (n - n / 2)) + (1 << (n - n / 2 - 1)) + l] +=
              1ll * g[i][1][l] * d[i][j];
        }
      }
    }
    return;
  }
  if (num + 1 <= n / 2) {
    k[num + 1] = now;
    dfs(now + 1, num + 1);
  }
  if (now - num <= n - n / 2) {
    ek[now - num] = now;
    dfs(now + 1, num);
  }
}
int main() {
  n = readint();
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  dfs(1, 0);
  for (int i = 0; i < (1 << (n - 1)); i++) printf("%lld ", ans[i]);
  printf("\n");
  return 0;
}
