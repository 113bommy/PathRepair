#include <bits/stdc++.h>
using namespace std;
char a[505];
int n, k, cnt;
int s[505], top;
int ch[505][10], val[505];
int d[505], f[505][505][11];
void ins(int x) {
  int len = strlen(a + 1), p = 0;
  for (int i = 1; i <= len; p = ch[p][(a[i] ^ 48)], i++)
    if (!ch[p][(a[i] ^ 48)]) ch[p][(a[i] ^ 48)] = ++cnt;
  val[p] += x;
}
void dp(int x) {
  s[++top] = x;
  for (int i = 0; i <= 9; i++)
    if (ch[x][i]) d[ch[x][i]] = d[x] + 1, dp(ch[x][i]);
  for (int i = 0; i <= 9; i++)
    if (ch[x][i])
      for (int j = 1; j <= top; j++)
        for (int v = k; ~v; v--) {
          f[x][s[j]][v] += f[ch[x][i]][s[j]][0];
          for (int p = 0; p <= v; p++)
            f[x][s[j]][v] =
                min(f[x][s[j]][v], f[x][s[j]][v - p] + f[ch[x][i]][s[j]][p]);
        }
  for (int j = 1; j <= top; j++) {
    f[x][s[j]][0] += val[x] * (d[x] - d[s[j]]);
    for (int v = 1; v <= k; v++)
      f[x][s[j]][v] =
          min(f[x][s[j]][v] + val[x] * (d[x] - d[s[j]]), f[x][x][v - 1]);
  }
  top--;
}
signed main() {
  cin >> n >> k;
  for (int x, i = 1; i <= n; i++) scanf("%s%d", a + 1, &x), ins(x);
  dp(0);
  cout << f[0][0][k];
}
