#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int n, m;
long long b[MAX], g[MAX];
long long solve() {
  long long ret = 0;
  sort(b, b + n, greater<long long>());
  sort(g, g + m, greater<long long>());
  if (b[0] > g[m - 1]) return -1;
  for (int i = 0; i < n; i++) ret += b[i] * ((long long)m);
  for (int j = 0; j < n; j++) ret += g[j];
  int i = 0, satisfied = 0, curCount = 0;
  for (int j = 0; j < m; j++) {
    while (i <= n) {
      if (b[i] <= g[j] &&
          (curCount < m - 1 || (curCount == m - 1 && b[i] == g[j]))) {
        ret -= b[i];
        satisfied++;
        curCount++;
        break;
      } else {
        i++;
        curCount = 0;
      }
    }
  }
  return (satisfied < m) ? -1ll : ret;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
  for (int j = 0; j < m; j++) scanf("%lld", &g[j]);
  printf("%lld\n", solve());
  return 0;
}
