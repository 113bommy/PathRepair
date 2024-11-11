#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN = 3e2 + 50;
const int MAXM = 2e4 + 50;
const int MOD = 1e9 + 7;
int n, p[MAXN][MAXN];
bool ok[MAXN];
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) scanf("%d", &p[i][j]);
    for (int i = 1; i <= n; i++) scanf("%d", &p[0][i]);
    for (int i = 1; i <= n; i++) {
      for (int k = 1; k <= n; k++) {
        ok[p[0][k]] = true;
        for (int j = 1; j < k; j++)
          if (p[0][j] < p[0][k] && ok[p[0][k]] != i) {
            ok[p[0][k]] = false;
            break;
          }
      }
      for (int j = 1; j <= n; j++) {
        if (p[i][j] == i) continue;
        if (ok[p[i][j]]) {
          printf("%d%c", p[i][j], " \n"[i == n]);
          break;
        }
      }
    }
  }
  return 0;
}
