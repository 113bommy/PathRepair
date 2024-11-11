#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k, rt;
int p[N], v[N];
map<int, int> ps;
int e[N][2];
vector<int> val;
long long sum[N];
int sz[N];
void add(int p, int x) {
  if (v[p] > v[x]) {
    e[p][0] = x;
  } else {
    e[p][1] = x;
  }
}
bool leaf(int i) { return (e[i][0] == 0 && e[i][1] == 0); }
int big(int x) {
  int psval = lower_bound(val.begin(), val.end(), x) - val.begin();
  return val[psval + 1];
}
int small(int x) {
  int psval = lower_bound(val.begin(), val.end(), x) - val.begin();
  return val[psval - 1];
}
void dfs(int u, int sm, int z) {
  if (leaf(u)) {
    sum[u] = sm;
    sz[u] = z;
    return;
  }
  dfs(e[u][0], sm + big(v[u]), z + 1);
  dfs(e[u][1], sm + small(v[u]), z + 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", p + i, v + i);
    val.push_back(v[i]);
  }
  for (int i = 1; i <= n; ++i) {
    if (p[i] == -1)
      rt = i;
    else
      add(p[i], i);
  }
  sort(val.begin(), val.end());
  for (int i = 1; i <= n; ++i) {
    ps[v[i]] = i;
  }
  dfs(rt, 0, 0);
  scanf("%d", &k);
  for (int i = 1; i <= k; ++i) {
    int x;
    scanf("%d", &x);
    int ii = lower_bound(val.begin(), val.end(), x) - val.begin();
    int pp;
    if (ii < val.size() && leaf(ps[val[ii]])) {
      pp = ps[val[ii]];
    } else {
      assert(ii);
      pp = ps[val[ii - 1]];
    }
    printf("%.10f\n", 1.0 * sum[pp] / sz[pp]);
  }
  return 0;
}
