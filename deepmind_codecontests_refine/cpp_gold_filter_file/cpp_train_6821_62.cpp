#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5 + 7;
const int Maxm = 5e3 + 7;
struct Query {
  int opt;
  int p, c;
} q[Maxn];
int n, m, k;
inline int pos(int i, int j) { return (i - 1) * m + j; }
bool pr[Maxm], pc[Maxm];
int res[Maxn];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; ++i) scanf("%d%d%d", &q[i].opt, &q[i].p, &q[i].c);
  reverse(q + 1, q + k + 1);
  for (int i = 1; i <= k; ++i) {
    if (q[i].opt == 1) {
      if (pr[q[i].p]) continue;
      pr[q[i].p] = true;
      for (int j = 1; j <= m; ++j)
        if (res[pos(q[i].p, j)] == 0) res[pos(q[i].p, j)] = q[i].c;
    } else {
      if (pc[q[i].p]) continue;
      pc[q[i].p] = true;
      for (int j = 1; j <= n; ++j)
        if (res[pos(j, q[i].p)] == 0) res[pos(j, q[i].p)] = q[i].c;
    }
  }
  for (int i = 1; i <= n * m; ++i) printf("%d%c", res[i], i % m ? ' ' : '\n');
}
