#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const int Minf = 0x7f7f7f7f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const long long MINF = 0x7f7f7f7f7f7f7f7fll;
const int N = 2050;
int x[N * N], y[N * N];
bitset<N * 2> a[N];
int n, m;
void guass() {
  for (int i = (1); i <= n; ++i) {
    for (int j = (i); j <= n; ++j)
      if (a[j][i]) {
        if (j != i) swap(a[j], a[i]);
        break;
      }
    for (int j = (1); j <= n; ++j)
      if (a[j][i] && i != j) a[j] ^= a[i];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= m; ++i) scanf("%d%d", &x[i], &y[i]), a[x[i]][y[i]] = 1;
  for (int i = (1); i <= n; ++i) a[i][i + n] = 1;
  guass();
  for (int i = (1); i <= m; ++i) {
    if (a[y[i]][x[i] + n])
      puts("NO");
    else
      puts("YES");
  }
}
