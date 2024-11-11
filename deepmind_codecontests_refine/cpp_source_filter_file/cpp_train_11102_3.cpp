#include <bits/stdc++.h>
using namespace std;
const int B = 172;
const int maxn = 44000;
const int maxm = 20;
unordered_map<bitset<B>, int> mp;
bool vis[maxm][maxn];
bitset<B> a[maxn];
int nxt[maxn][10];
int cnt;
int bit[20];
long long dp[20][10][maxn];
long long solve(long long cnt, int k) {
  if (cnt = 0) return 1;
  int m = 0;
  while (cnt) bit[m++] = cnt % 10, cnt /= 10;
  int u = 1;
  long long ret = 0;
  for (int i = m - 1; i >= 0; i--) {
    for (int j = 0; j < bit[i] + (i == 0); j++) ret += dp[i][k][nxt[u][j]];
    u = nxt[u][bit[i]];
  }
  return ret;
}
int main() {
  bitset<B> cur;
  cur.set(0);
  mp[cur] = 1;
  a[1] = cur;
  vis[0][1] = 1;
  cnt = 1;
  for (int i = 1; i < maxm; i++) {
    for (int u = 1; u <= cnt; u++)
      if (vis[i - 1][u]) {
        for (int j = 0; j < 10; j++) {
          if (!nxt[u][j]) {
            if (j == 0) {
              nxt[u][j] = u;
            } else {
              cur.reset();
              for (int k = j; k < B; k++)
                if (a[u][k]) cur[k - j] = 1;
              for (int k = 0; k < B - j; k++)
                if (a[u][k]) cur[k + j] = 1;
              for (int k = 1; k < j; k++)
                if (a[u][k]) cur[j - k] = 1;
              if (mp.count(cur)) {
                nxt[u][j] = mp[cur];
              } else {
                nxt[u][j] = mp[cur] = ++cnt;
                a[cnt] = cur;
              }
            }
          }
          vis[i][nxt[u][j]] = 1;
        }
      }
  }
  for (int j = 1; j <= cnt; j++) {
    int k = 0;
    for (k = 0; k < 10; k++)
      if (a[j][k]) break;
    for (; k < 10; k++) dp[0][k][j] = 1;
  }
  for (int j = 1; j < maxm - 1; j++) {
    for (int k = 1; k <= cnt; k++)
      if (vis[maxm - 1 - j][k]) {
        for (int i = 0; i < 10; i++) {
          for (int l = 0; l < 10; l++) dp[j][l][k] += dp[j - 1][l][nxt[k][i]];
        }
      }
  }
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    long long l, r;
    int k;
    scanf("%I64d%I64d%d", &l, &r, &k);
    printf("%I64d\n", solve(r, k) - solve(l - 1, k));
  }
  return 0;
}
