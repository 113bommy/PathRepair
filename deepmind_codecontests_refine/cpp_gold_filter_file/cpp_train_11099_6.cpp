#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e11;
struct souvik {
  int d, f, t, c;
} q[100003];
long long int ans[1000005], f[1000005], e[1000005];
bool comp(souvik q, souvik w) { return q.d < w.d; }
int main() {
  int n, m, i, j, k;
  long long int res = 0;
  scanf("%d %d %d", &n, &m, &k);
  for (i = 0; i < m; i++)
    scanf("%d %d %d %d", &q[i].d, &q[i].f, &q[i].t, &q[i].c);
  sort(q, q + m, comp);
  for (i = 1; i <= n; i++) ans[i] = INF, res += ans[i];
  j = 0;
  for (i = 0; i <= 1000000; i++) {
    while (j < m && q[j].d == i) {
      if (q[j].t == 0) {
        if (ans[q[j].f] > q[j].c) {
          res += q[j].c - ans[q[j].f];
          ans[q[j].f] = q[j].c;
        }
      }
      j++;
    }
    f[i] = res;
  }
  res = 0;
  for (i = 1; i <= n; i++) ans[i] = INF, res += ans[i];
  j = m - 1;
  for (i = 1000000; i >= 0; i--) {
    while (j >= 0 && q[j].d == i) {
      if (q[j].f == 0) {
        if (ans[q[j].t] > q[j].c) {
          res += q[j].c - ans[q[j].t];
          ans[q[j].t] = q[j].c;
        }
      }
      j--;
    }
    e[i] = res;
  }
  res = INF + 5LL;
  for (i = 1; i + k <= 1000000; i++) res = min(res, f[i - 1] + e[i + k]);
  if (res > INF)
    printf("-1\n");
  else
    printf("%lld\n", res);
  return 0;
}
