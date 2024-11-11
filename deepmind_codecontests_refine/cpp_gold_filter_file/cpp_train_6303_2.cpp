#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const int MAXM = 110;
map<long long, int> p;
long long a[MAXN];
long long use[MAXM];
int main() {
  int n;
  scanf("%d", &n);
  int cnt = 0;
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= n; i++) {
    int k;
    scanf("%d", &k);
    long long u, v, w;
    if (k == 1) {
      scanf("%I64d%I64d%I64d", &u, &v, &w);
      use[0] = 0;
      while (u >= 1) {
        if (!p[u]) {
          cnt++;
          p[u] = cnt;
        }
        use[0]++;
        use[use[0]] = u;
        u /= 2;
      }
      int j = 1;
      while (v >= 1) {
        if (!p[v]) {
          cnt++;
          p[v] = cnt;
        }
        while (v < use[j]) {
          j++;
        }
        if (v == use[j]) {
          break;
        }
        a[p[v]] += w;
        v /= 2;
      }
      for (int t = 1; t < j; t++) {
        a[p[use[t]]] += w;
      }
    } else {
      long long ans = 0;
      scanf("%I64d%I64d", &u, &v);
      use[0] = 0;
      while (u >= 1) {
        if (!p[u]) {
          cnt++;
          p[u] = cnt;
        }
        use[0]++;
        use[use[0]] = u;
        u /= 2;
      }
      int j = 1;
      while (v >= 1) {
        if (!p[v]) {
          cnt++;
          p[v] = cnt;
        }
        while (v < use[j]) {
          j++;
        }
        if (v == use[j]) {
          break;
        }
        ans += a[p[v]];
        v /= 2;
      }
      for (int t = 1; t < j; t++) {
        ans += a[p[use[t]]];
      }
      printf("%I64d\n", ans);
    }
  }
  return 0;
}
