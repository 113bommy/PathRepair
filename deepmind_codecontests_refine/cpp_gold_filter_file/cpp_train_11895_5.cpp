#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
void read(int& val) {
  int x = 0;
  int bz = 1;
  char c;
  for (c = getchar(); (c < '0' || c > '9') && c != '-'; c = getchar())
    ;
  if (c == '-') {
    bz = -1;
    c = getchar();
  }
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48;
  val = x * bz;
}
const int mod = 1e9 + 7;
const int maxn = 1e6 + 11;
int n, m, k;
int lef[110][110], rig[110][110], dp[110][110];
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= n; i++) {
    int k, l, r;
    read(k);
    for (int j = 1; j <= k; j++) {
      read(l);
      read(r);
      for (int zz = l; zz <= r; zz++) {
        lef[i][zz] = l;
        rig[i][zz] = r;
      }
    }
  }
  for (int l = m; l >= 1; l--) {
    for (int r = l; r <= m; r++) {
      for (int k = l; k <= r; k++) {
        int cnt = 0;
        for (int z = 1; z <= n; z++) {
          if (lef[z][k] >= l && rig[z][k] <= r) cnt++;
        }
        dp[l][r] = max(dp[l][r], dp[l][k - 1] + cnt * cnt + dp[k + 1][r]);
      }
    }
  }
  printf("%d\n", dp[1][m]);
  return 0;
}
