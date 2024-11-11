#include <bits/stdc++.h>
using namespace std;
const int maxn = 250 + 10;
char s[maxn][maxn], str[maxn << 1][maxn];
int tot[26], f[maxn << 1], xo[maxn][maxn];
bool vis[maxn << 1];
long long mod1 = 1e9 + 7, mod2 = 998244353;
struct node {
  long long x, y;
  bool operator==(const node &b) { return x == b.x && y == b.y; }
  node operator+(const node &b) {
    return {(x + b.x + mod1) % mod1, (y + b.y + mod2) % mod2};
  }
  node operator-(const node &b) {
    return {(x - b.x + mod1) % mod1, (y - b.y + mod2) % mod2};
  }
} hsum[maxn][maxn], value[maxn << 1];
node Hash() {
  long long sum1 = 0, sum2 = 0;
  int i;
  for (i = 0; i < 26; i++) {
    sum1 = (sum1 * 26 + tot[i]) % mod1;
    sum2 = (sum2 * 26 + tot[i]) % mod2;
  }
  return {sum1, sum2};
}
int main() {
  int n, m, sum = 0, i, j, k, l, r, mid, g;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    memset(tot, 0, sizeof(tot));
    for (j = 1; j <= m; j++) {
      tot[s[i][j] - 97]++;
      hsum[i][j] = Hash();
      xo[i][j] = xo[i][j - 1] ^ (1 << (s[i][j] - 97));
    }
  }
  for (i = 1; i <= m; i++)
    for (j = i; j <= m; j++) {
      strcpy(str[0], "#");
      vis[0] = 0;
      l = 0;
      for (k = 1; k <= n; k++) {
        l++;
        strcpy(str[l], "#");
        value[l] = {-1, -1};
        vis[l] = 1;
        l++;
        r = xo[k][j] ^ xo[k][i - 1];
        vis[l] = (r == 0 || !(r - (r & -r)));
        value[l] = hsum[k][j] - hsum[k][i - 1];
      }
      l++;
      strcpy(str[l], "#");
      value[l] = {-1, -1};
      vis[l] = 1;
      l++;
      strcpy(str[l], "#");
      vis[l] = 0;
      g = n << 1;
      r = 0, mid = 0;
      for (l = 2; l <= g; l++) {
        if (l < r)
          f[l] = min(f[(mid << 1) - l], f[mid] + mid - l);
        else
          f[l] = 1;
        while (vis[l + f[l]] && vis[l - f[l]] &&
               value[l + f[l]] == value[l - f[l]])
          f[l]++;
        if (f[l] + l > r) {
          r = f[l] + l;
          mid = l;
        }
        if (vis[l]) sum += f[l] >> 1;
      }
    }
  printf("%d", sum);
  return 0;
}
