#include <bits/stdc++.h>
using namespace std;
char s[5][109][109], sss[109];
bool vis[5][109][109];
const int inf = 0x3f3f3f3f;
int a[5];
int main() {
  int n;
  int sum, cnt;
  int l;
  while (cin >> n) {
    sum = inf;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < n; j++) scanf("%s", s[i][j]);
    }
    for (int i = 0; i < 4; i++) a[i] = i;
    do {
      l = 0;
      cnt = 0;
      memset(vis, 0, sizeof(vis));
      for (int i = 0; i < 4; i += 2) {
        if (i == 2) {
          for (int k = 0; k < n; k++) {
            if (s[a[i - 2]][n - 1][k] != s[a[i]][0][k] &&
                vis[a[i - 2]][n - 2][k] == 0) {
            } else if (s[a[i - 2]][n - 1][k] == s[a[i]][0][k] &&
                       vis[a[i - 2]][n - 1][k] == 1) {
            } else {
              cnt++;
              vis[a[i]][0][k] = 1;
            }
            if (s[a[i - 1]][n - 1][k] != s[a[i + 1]][0][k] &&
                vis[a[i - 1]][n - 1][k] == 0) {
            } else if (s[a[i - 1]][n - 1][k] == s[a[i + 1]][0][k] &&
                       vis[a[i - 1]][n - 1][k] == 1) {
            } else {
              cnt++;
              vis[a[i + 1]][0][k] = 1;
            }
          }
          l = 1;
        }
        for (int j = l; j < n; j++) {
          if (j == 0 && s[a[i]][j][0] == s[a[i + 1]][0][n - 1]) {
            vis[a[i + 1]][0][n - 1] = 1;
            cnt++;
          }
          for (int k = 0, k1 = n - 1; k1 >= 0, k < n; k1--, k++) {
            if (j == 0) {
              if (k == 0) continue;
              if (s[a[i]][j][k] != s[a[i + 1]][j][k1]) {
                if (s[a[i]][j][k] != s[a[i]][j][k - 1] &&
                    vis[a[i]][j][k - 1] == 0)
                  continue;
                else if (s[a[i]][j][k] == s[a[i]][j][k - 1] &&
                         vis[a[i]][j][k - 1] == 1) {
                  continue;
                } else {
                  cnt += 2;
                  vis[a[i + 1]][j][k1] = 1;
                  vis[a[i]][j][k] = 1;
                }
              } else {
                if (s[a[i]][j][k] == s[a[i]][j][k - 1] &&
                    vis[a[i]][j][k - 1] == 0) {
                  vis[a[i]][j][k] = 1;
                  cnt++;
                } else if (s[a[i]][j][k] != s[a[i]][j][k - 1] &&
                           vis[a[i]][j][k - 1] == 1) {
                  vis[a[i]][j][k] = 1;
                  cnt++;
                } else {
                  vis[a[i + 1]][j][k1] = 1;
                  cnt++;
                }
              }
            } else {
              if (s[a[i]][j - 1][k] != s[a[i]][j][k] &&
                  vis[a[i]][j - 1][k] == 0) {
              } else if (s[a[i]][j - 1][k] == s[a[i]][j][k] &&
                         vis[a[i]][j - 1][k] == 1) {
              } else {
                cnt++;
                vis[a[i]][j][k] = 1;
              }
              if (s[a[i + 1]][j - 1][k] != s[a[i + 1]][j][k] &&
                  vis[a[i + 1]][j - 1][k] == 0) {
              } else if (s[a[i + 1]][j - 1][k] == s[a[i + 1]][j][k] &&
                         vis[a[i + 1]][j - 1][k] == 1) {
              } else {
                cnt++;
                vis[a[i + 1]][j][k] = 1;
              }
            }
          }
        }
      }
      cnt = min(cnt, n * n * 4 - cnt);
      sum = min(cnt, sum);
    } while (next_permutation(a, a + 4));
    cout << sum << endl;
  }
  return 0;
}
