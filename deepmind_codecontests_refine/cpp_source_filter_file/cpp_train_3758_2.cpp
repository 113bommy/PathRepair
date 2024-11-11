#include <bits/stdc++.h>
using namespace std;
struct P {
  int id, v;
} p[3010];
int n, m, num, pe[3010];
long long ans = 1e18, c;
vector<int> vt[3010];
bool cmp(P x, P y) { return x.v < y.v; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", &p[i].id, &p[i].v), vt[p[i].id].push_back(p[i].v);
  for (int i = 1; i <= m; ++i)
    if (vt[i].size()) sort(vt[i].begin(), vt[i].end());
  sort(p + 1, p + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    c = 0, num = vt[1].size();
    for (int j = 2; j <= m; ++j)
      for (int k = 0; k <= (int)vt[j].size() - i; ++k) c += vt[j][k], ++num;
    if (num < i) {
      for (int j = 1; j <= m; ++j) pe[j] = 0;
      for (int j = 1; j <= n && num < i; ++j)
        if (p[j].id != 1) {
          ++pe[p[j].id];
          if (pe[p[j].id] > (int)vt[j].size() - i + 1) c += p[j].v, ++num;
        }
    }
    ans = min(ans, c);
  }
  printf("%I64d", ans);
  return 0;
}
