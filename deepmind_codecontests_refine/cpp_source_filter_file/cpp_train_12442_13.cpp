#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e16;
int c[101][101];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  int ans = 1e9 + 7;
  for (int i = 0; i < n; i++) {
    int cmin = 1e9 + 7;
    for (int j = 0; j < m; j++) {
      int tmp;
      scanf("%d", &tmp);
      cmin = min(cmin, tmp);
    }
    ans = min(ans, cmin);
  }
  printf("%d", ans);
  return 0;
}
