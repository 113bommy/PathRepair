#include <bits/stdc++.h>
using namespace std;
vector<int> g[20];
int mm[20][20];
long long dp[1 << 13][13];
int cnt[1 << 14];
vector<int> gg;
void solve(int f, int i, int j, int n) {
  int flag = 0;
  int w2 = i ^ f;
  for (int q = 0; q < n; q++) {
    if (f & (1 << q)) {
      for (int w1 = 0; w1 < n; w1++) {
        if (w2 & (1 << w1)) {
          if (mm[w1][q] != -1 && mm[w1][q] != j) {
            flag = 1;
            break;
          }
        }
      }
      if (flag) break;
      for (int w1 = 0; w1 < n; w1++) {
        if (f & (1 << w1)) {
          if (mm[w1][q] != -1 && (f & (1 << mm[w1][q])) == 0) {
            flag = 1;
            break;
          }
        }
      }
    }
  }
  if (!flag) {
    int all = 0;
    int x = 0;
    for (int v : g[j]) {
      if (f & (1 << v)) {
        all++;
        x = v;
      }
    }
    if (all <= 1) {
      if (all == 0) {
        for (int q = 0; q < n; q++) {
          if (f & (1 << q)) {
            for (int v : g[q]) {
              if ((f & (1 << v)) == 0) {
                flag = 1;
                break;
              }
            }
            if (flag) break;
          }
        }
        if (flag == 0) {
          for (int q = 0; q < n; q++) {
            if (f & (1 << q)) {
              dp[i][j] += dp[i ^ f][j] * dp[f][q];
            }
          }
        }
      } else {
        for (int q = 0; q < n; q++) {
          if (f & (1 << q)) {
            if (q == x) {
              for (int v : g[q]) {
                if ((f & (1 << v)) == 0) {
                  if (v == j) continue;
                  flag = 1;
                  break;
                }
              }
              continue;
            }
            for (int v : g[q]) {
              if ((f & (1 << v)) == 0) {
                flag = 1;
                break;
              }
            }
            if (flag) break;
          }
        }
        if (flag == 0) {
          dp[i][j] += dp[i ^ f][j] * dp[f][x];
        }
      }
    }
  }
}
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i < (1 << 13); i++) {
    cnt[i] = cnt[i & (i - 1)] + 1;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  memset(mm, -1, sizeof(mm));
  for (int i = 1; i <= q; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == b) {
      if (a != c) {
        printf("0\n");
        return 0;
      }
    }
    a--;
    b--;
    c--;
    if (mm[a][b] != -1) {
      if (mm[a][b] != c) {
        printf("0\n");
        return 0;
      }
    }
    mm[a][b] = c;
    mm[b][a] = c;
  }
  for (int i = 0; i < n; i++) {
    dp[1 << i][i] = 1;
  }
  int p = 1 << n;
  for (int i = 2; i < p; i++) {
    if (cnt[i] == 1) continue;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        int last = 0;
        for (int f = 0; f < n; f++) {
          if (i & (1 << f)) {
            if (f != j) last = f;
          }
        }
        int w = i ^ (1 << j) ^ (1 << last);
        for (int f = w; f; f = (f - 1) & w) {
          solve(f ^ (1 << last), i, j, n);
        }
        solve(1 << last, i, j, n);
      }
    }
  }
  printf("%I64d\n", dp[p - 1][0]);
}
