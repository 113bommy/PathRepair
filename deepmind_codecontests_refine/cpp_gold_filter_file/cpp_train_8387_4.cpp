#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 100;
int n, cnt, a, b, tot;
int ans[MAXN];
struct P {
  int id, t, sum;
};
vector<P> p[MAXN];
P te;
int dfs(int rt) {
  if (p[rt].size() == 0) return 0;
  int ret = 0;
  for (int i = 0; i < p[rt].size(); ++i) {
    p[rt][i].sum = p[rt][i].t + dfs(p[rt][i].id);
    if (p[rt][i].sum == tot / 3) {
      ans[cnt++] = p[rt][i].id;
    } else
      ret += p[rt][i].sum;
  }
  return ret;
}
int main() {
  tot = 0;
  cnt = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    te.id = i;
    scanf("%d%d", &a, &b);
    te.t = b;
    p[a].push_back(te);
    tot += b;
  }
  if (tot % 3 != 0) {
    printf("-1   \n");
    return 0;
  }
  dfs(0);
  if (cnt >= 3) {
    printf("%d %d\n", ans[0], ans[1]);
  } else
    printf("-1\n");
  return 0;
}
