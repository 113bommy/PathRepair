#include <bits/stdc++.h>
using namespace std;
string g[555];
char ag[555][555];
int dp[555][26][26];
int pa[555][26][26];
int rc[555][26][26];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }
  for (int i = 0; i < n; i++) {
    for (int x = 0; x < 26; x++) {
      for (int y = 0; y < 26; y++) {
        dp[i][x][y] = 99999999;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int x = 0; x < 26; x++) {
      for (int y = 0; y < 26; y++) {
        if (x != y) {
          int ans = 0;
          for (int j = 0; j < m; j++) {
            if (j & 1) {
              if (g[i][j] - 'a' != y) {
                ans++;
              }
            } else {
              if (g[i][j] - 'a' != x) {
                ans++;
              }
            }
          }
          rc[i][x][y] = ans;
        } else {
          rc[i][x][y] = 99999999;
        }
      }
    }
  }
  for (int x = 0; x < 26; x++) {
    for (int y = 0; y < 26; y++) {
      dp[0][x][y] = rc[0][x][y];
    }
  }
  int v;
  for (int i = 1; i < n; i++) {
    for (int x = 0; x < 26; x++) {
      for (int y = 0; y < 26; y++) {
        if (x != y) {
          for (int a = 0; a < 26; a++) {
            for (int b = 0; b < 26; b++) {
              if (a != b && a != x && b != y) {
                v = dp[i - 1][a][b] + rc[i][x][y];
                if (dp[i][x][y] > v) {
                  dp[i][x][y] = v;
                  pa[i][x][y] = 100 * a + b;
                }
              }
            }
          }
        }
      }
    }
  }
  int par;
  int ans = 99999999;
  for (int x = 0; x < 26; x++) {
    for (int y = 0; y < 26; y++) {
      if (ans > dp[n - 1][x][y]) {
        ans = dp[n - 1][x][y];
        par = 100 * x + y;
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    char f = par / 100 + 'a';
    char s = par % 100 + 'a';
    for (int j = 0; j < m; j++) {
      if (j & 1) {
        ag[i][j] = s;
      } else {
        ag[i][j] = f;
      }
    }
    ag[i][m] = 0;
    par = pa[i][f - 'a'][s - 'a'];
  }
  printf("%d\n", ans);
  for (int i = 0; i < n; i++) {
    printf("%s\n", ag[i]);
  }
  return 0;
}
