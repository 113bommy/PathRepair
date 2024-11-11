#include <bits/stdc++.h>
using namespace std;
int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || '9' < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f * x;
}
const int MAXN = 700;
const int INF = 0x3f3f3f3f;
const int Mod = (int)(1e9 + 7);
inline void Add(int &x, int y) {
  x += y;
  x >= Mod ? x -= Mod : x;
  return;
}
char num[MAXN + 7];
int f[MAXN + 5][MAXN + 5][10][2];
int main() {
  scanf("%s", num + 1);
  int n = strlen(num + 1);
  for (int i = 0; i <= 9; i++) f[0][0][i][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      for (int k = 1; k <= 9; k++)
        for (int l = 0; l <= 1; l++)
          for (int p = 0; p <= (l ? 9 : (num[i + 1] - '0')); p++)
            Add(f[i + 1][j + (p >= k)][k][l | (p < num[i + 1] - '0')],
                f[i][j][k][l]);
  int ans = 0;
  for (int k = 1; k <= 9; k++)
    for (int i = 1, tp = 1; i <= n; i++)
      Add(ans, 1ll * tp * (f[n][i][k][0] + f[n][i][k][1]) % Mod),
          tp = (tp * 10ll + 1) % Mod;
  printf("%d\n", ans);
  return 0;
}
