#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], sz[N], son[N] = {0};
long long res[N];
int times[N] = {0}, ans = 0;
vector<int> vec[N];
class SOLVE {
 public:
  long long a[N] = {0};
  void add(int pos, int val) {
    pos++;
    for (int i = pos; i < N; i += (i & (-i))) a[i] += val;
  }
  long long query(int pos) {
    pos++;
    long long res = 0;
    for (int i = pos; i; i -= (i & (-i))) res += a[i];
    return res;
  }
} num, sum;
void dfs1(int u, int from) {
  sz[u] = 1;
  for (int i = 0; i < vec[u].size(); i++) {
    int v = vec[u][i];
    if (v == from) continue;
    dfs1(v, u);
    if (sz[son[u]] < sz[v]) son[u] = v;
    sz[u] += sz[v];
  }
}
void update(int u, int from, int val) {
  num.add(times[a[u]], -1);
  sum.add(times[a[u]], -a[u]);
  times[a[u]] += val;
  num.add(times[a[u]], 1);
  sum.add(times[a[u]], a[u]);
  for (int i = 0; i < vec[u].size(); i++) {
    int v = vec[u][i];
    if (v == from) continue;
    update(v, u, val);
  }
}
int n;
int query() {
  int l = 1, r = n;
  int stand = num.query(n);
  while (l <= r) {
    int mid = (l + r) / 2;
    if (num.query(mid) == stand)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return sum.query(l) - sum.query(l - 1);
}
void dfs2(int u, int from, bool del) {
  for (int i = 0; i < vec[u].size(); i++) {
    int v = vec[u][i];
    if (v == from || v == son[u]) continue;
    dfs2(v, u, true);
  }
  if (son[u]) dfs2(son[u], u, false);
  num.add(times[a[u]], -1);
  sum.add(times[a[u]], -a[u]);
  times[a[u]]++;
  num.add(times[a[u]], 1);
  sum.add(times[a[u]], a[u]);
  for (int i = 0; i < vec[u].size(); i++) {
    int v = vec[u][i];
    if (v == from || v == son[u]) continue;
    update(v, u, 1);
  }
  res[u] = query();
  if (del) update(u, from, -1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    vec[u].push_back(v);
    vec[v].push_back(u);
  }
  dfs1(1, 0);
  dfs2(1, 0, false);
  for (int i = 1; i <= n; i++) printf("%lld%c", res[i], i == n ? '\n' : ' ');
}
