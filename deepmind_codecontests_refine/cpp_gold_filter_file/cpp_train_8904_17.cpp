#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
int n, m;
int a[605][605];
int main() {
  ios_base::sync_with_stdio(0);
  clock_t _ = clock();
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) scanf("%d", a[i] + j);
    int diff = 0;
    int u = n / 2, d = u + 1;
    for (int i = 1; i <= m; ++i) diff += abs(a[u][i] - a[d][i]);
    puts(diff > 20 * m ? "YES" : "NO");
  }
  return 0;
}
