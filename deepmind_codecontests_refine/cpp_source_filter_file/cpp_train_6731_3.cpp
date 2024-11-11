#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const long long MOD = 1000000007;
const double eps = 1e-10;
int a[MAXN];
int arrM[MAXN][MAXN];
int ask[MAXN];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] == j) {
        arrM[j][i] = arrM[j][i - 1] + 1;
      } else
        arrM[j][i] = arrM[j][i - 1];
    }
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &ask[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      bool ok = true;
      for (int k = 1; k <= m; k++) {
        if (ask[k] != arrM[k][j] - arrM[k][i]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}
