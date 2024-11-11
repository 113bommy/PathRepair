#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
int n, m, r;
int mp[maxn][maxn];
int psum[maxn][maxn];
int blocks[maxn];
int pre[maxn][maxn], pcnt[maxn][maxn];
int suf[maxn][maxn], scnt[maxn][maxn];
int pl[maxn];
void work() {
  blocks[0] = r;
  for (int i = 1; i <= r; i++) {
    blocks[i] = blocks[i - 1];
    while (i * i + blocks[i] * blocks[i] > r * r) blocks[i]--;
  }
  memset(mp, 0, sizeof(mp));
  for (int i = r + 1; i <= n - r; i++) {
    for (int j = r + 1; j <= m - r; j++) {
      for (int k = -r; k <= r; k++) {
        mp[i][j] += psum[i + k][j + blocks[abs(k)]] -
                    psum[i + k][j - blocks[abs(k)] - 1];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (mp[i][j] > pre[i][j - 1]) {
        pre[i][j] = mp[i][j];
        pcnt[i][j] = 1;
      } else if (mp[i][j] == pre[i][j - 1]) {
        pre[i][j] = mp[i][j];
        pcnt[i][j] = pcnt[i][j - 1] + 1;
      } else {
        pre[i][j] = pre[i][j - 1];
        pcnt[i][j] = pcnt[i][j - 1];
      }
    }
    for (int j = m; j >= 1; j--) {
      if (mp[i][j] > suf[i][j + 1]) {
        suf[i][j] = mp[i][j];
        scnt[i][j] = 1;
      } else if (mp[i][j] == suf[i][j + 1]) {
        suf[i][j] = mp[i][j];
        scnt[i][j] = scnt[i][j + 1] + 1;
      } else {
        suf[i][j] = suf[i][j + 1];
        scnt[i][j] = scnt[i][j + 1];
      }
    }
  }
  for (int i = 0; i <= 2 * r; i++) {
    for (int j = i - r; j <= r; j++) {
      int dis1 = j, dis2 = j - i;
      pl[i] = max(pl[i], blocks[abs(dis1)] + blocks[abs(dis2)] + 1);
    }
  }
  int ans1 = 0;
  long long ans2 = 0;
  for (int i = r + 1; i <= n - r; i++) {
    for (int j = r + 1; j <= m - r; j++) {
      for (int k = r + 1; k <= n - r; k++) {
        int dis = abs(i - k);
        if (dis > r * 2) {
          if (pre[k][m] > 0) {
            if (pre[k][m] + mp[i][j] > ans1) {
              ans1 = pre[k][m] + mp[i][j];
              ans2 = pcnt[k][m];
            } else if (pre[k][m] + mp[i][j] == ans1) {
              ans2 += pcnt[k][m];
            }
          }
          continue;
        }
        if (j - pl[dis] >= r + 1) {
          if (pre[k][j - pl[dis]] + mp[i][j] > ans1) {
            ans1 = pre[k][j - pl[dis]] + mp[i][j];
            ans2 = pcnt[k][j - pl[dis]];
          } else if (pre[k][j - pl[dis]] + mp[i][j] == ans1) {
            ans2 += pcnt[k][j - pl[dis]];
          }
        }
        if (j + pl[dis] <= m - r) {
          if (suf[k][j + pl[dis]] + mp[i][j] > ans1) {
            ans1 = suf[k][j + pl[dis]] + mp[i][j];
            ans2 = scnt[k][j + pl[dis]];
          } else if (suf[k][j + pl[dis]] + mp[i][j] == ans1) {
            ans2 += scnt[k][j + pl[dis]];
          }
        }
      }
    }
  }
  ans2 /= 2;
  printf("%d %lld\n", ans1, ans2);
}
int main() {
  scanf("%d%d%d", &n, &m, &r);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &mp[i][j]);
      psum[i][j] = psum[i][j - 1] + mp[i][j];
    }
  }
  work();
}
