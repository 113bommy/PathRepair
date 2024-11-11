#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
vector<int> g[maxn];
int deg[maxn];
int main() {
  int n, s;
  scanf("%d%d", &n, &s);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    deg[u]++, deg[v]++;
  }
  if (n == 2) return printf("%.10lf\n", 1.0 * s), 0;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += (deg[i] == 1);
  }
  printf("%.10lf\n", 2.0 * s / cnt);
}
