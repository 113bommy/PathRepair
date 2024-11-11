#include <bits/stdc++.h>
using namespace std;
int entries[1010000][2];
long long has[1010000];
long long power[1010000];
int main() {
  int i, j;
  long long ans = 0;
  int n, m, u, v, p = 17;
  scanf("%d%d", &n, &m);
  power[0] = 1;
  for (i = 1; i <= n; i++) power[i] = power[i - 1] * p;
  for (i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    u--;
    v--;
    has[u] += power[v];
    has[v] += power[u];
    entries[i][0] = u;
    entries[i][1] = v;
  }
  for (i = 0; i < m; i++) {
    u = entries[i][0];
    v = entries[i][1];
    if (has[u] + power[u] == has[v] + power[v]) ans++;
  }
  sort(has, has + n);
  for (i = 0; i < n; i = j) {
    for (j = i; j < n && has[j] == has[i]; j++)
      ;
    long long temp = j - i;
    ans += temp * (temp - 1) / 2;
  }
  printf("%I64d\n", ans);
  return 0;
}
