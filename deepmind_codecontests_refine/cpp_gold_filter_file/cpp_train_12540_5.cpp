#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int MAXN = 2005;
int n, m;
char s[MAXN], p[MAXN];
int to[MAXN], f[MAXN][MAXN];
void solve() {
  scanf("%s%s", s, p);
  n = strlen(s);
  m = strlen(p);
  for (int i = 0; i < n; i++) {
    to[i] = n + 1;
    int k = 0;
    for (int j = i; j < n; j++) {
      if (s[j] == p[k]) {
        k++;
        if (k == m) {
          to[i] = j + 1;
          break;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      f[i + 1][j] = max(f[i + 1][j], f[i][j]);
      f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j]);
      if (to[i] != n + 1) {
        int nx = to[i] - i - m + j;
        f[to[i]][nx] = max(f[to[i]][nx], f[i][j] + 1);
      }
    }
  }
  for (int i = 0; i <= n; i++) printf("%d ", f[n][i]);
  printf("\n");
}
int main() {
  solve();
  return 0;
}
