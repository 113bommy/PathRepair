#include <bits/stdc++.h>
using namespace std;
void ch_max(int &x, int y) {
  if (x < y) x = y;
}
void ch_min(int &x, int y) {
  if (x > y) x = y;
}
const double pi = acos(-1.0);
const double eps = 1e-9;
int SEED = 13331;
const int N = 1000005;
long long pw[N];
long long my[N];
long long all[N * 2];
int n, m;
int main() {
  int i, j, k, t, nc = 0;
  while (scanf("%d%d", &n, &m) != EOF) {
    pw[0] = 1;
    for (i = 1; i < N; ++i) pw[i] = pw[i - 1] * SEED;
    memset(my, 0, sizeof(my));
    for (i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      my[u] += pw[v];
      my[v] += pw[u];
    }
    int cnt = 0;
    for (i = 1; i <= n; ++i) {
      all[cnt++] = my[i];
      all[cnt++] = my[i] + pw[i];
    }
    sort(all, all + cnt);
    long long ans = 0;
    for (i = 0; i < cnt; ++i) {
      k = upper_bound(all, all + cnt, all[i]) - all;
      ans += k;
    }
    cout << ans << endl;
  }
  return 0;
}
