#include <bits/stdc++.h>
using namespace std;
const int Maxn = 500010;
int n, m, K;
map<string, int> mp;
string s;
int bit[1 << 15];
int nxt[Maxn][16], f[230][1 << 15];
int a[Maxn];
void down(int &x, int y) {
  if (x > y) x = y;
}
int main() {
  int i, j, k;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    cin >> s;
    mp[s] = i;
  }
  scanf("%d", &m);
  bit[0] = 0;
  for (i = 1; i < 1 << n; i++) bit[i] = bit[i >> 1] + (i & 1);
  int zs = n * (n - 1) / 2, mx = 1 << n;
  int ans = -1, ansnum;
  for (i = 1; i <= m; i++) {
    scanf("%d", &K);
    for (j = 1; j <= K; j++) {
      cin >> s;
      if (mp.count(s))
        a[j] = mp[s];
      else
        a[j] = 0;
    }
    for (j = 1; j <= n; j++) nxt[K + 1][j] = nxt[K][j] = K + 1;
    for (j = K - 1; j >= 0; j--) {
      for (k = 1; k <= n; k++) nxt[j][k] = nxt[j + 1][k];
      if (a[j + 1] != 0) nxt[j][a[j + 1]] = j + 1;
    }
    for (j = 0; j <= zs; j++)
      for (k = 0; k < mx; k++) f[j][k] = K + 1;
    f[0][0] = 0;
    for (j = 0; j <= zs; j++) {
      for (k = 0; k < mx; k++) {
        for (int x = 1; x <= 15; x++)
          if (!(k & (1 << x - 1)))
            down(f[j + bit[k >> x]][k | (1 << x - 1)], nxt[f[j][k]][x]);
      }
    }
    for (j = 0; j <= zs; j++)
      if (f[j][mx - 1] != K + 1) break;
    if (zs - j + 1 > ans) ans = zs - j + 1, ansnum = i;
  }
  if (ans == -1) {
    printf("Brand new problem!\n");
    return 0;
  }
  printf("%d\n", ansnum);
  printf("[:");
  for (i = 1; i <= ans; i++) printf("|");
  printf(":]\n");
  return 0;
}
