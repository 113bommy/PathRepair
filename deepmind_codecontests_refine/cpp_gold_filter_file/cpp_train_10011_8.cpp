#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const int SQ = 400;
int n, q, p, sq;
vector<int> g[N];
int a[N], b[N], x[N], y[N];
int L[N], R[N], dfs_cnt = 0;
void DFS(int node) {
  L[node] = R[node] = dfs_cnt++;
  a[L[node]] = x[node];
  b[L[node]] = y[node];
  b[L[node]] = abs(b[L[node]]);
  for (int i = 0; i < (int)g[node].size(); i++) {
    x[g[node][i]] += x[node];
    y[g[node][i]] += y[node];
    DFS(g[node][i]);
    R[node] = R[g[node][i]];
  }
}
int inc[N / SQ], mx[N / SQ];
int sz[N / SQ], last[N / SQ];
pair<long long, pair<int, long long> > v[N / SQ][SQ];
pair<int, long long> v2[SQ];
inline long long get(int a1, long long b1, int a2, long long b2) {
  if (a1 == a2) {
    if (b2 >= b1) return -(long long)1e18;
    return (long long)1e18;
  }
  return ((b1 - b2) / (a2 - a1)) +
         ((b1 >= b2 && (abs(b1 - b2) % abs(a2 - a1) != 0)) ? 1 : 0);
}
void build(int idx) {
  int num = 0;
  mx[idx] = -2000000000;
  for (int i = idx * sq; i < n && i < (idx + 1) * sq; i++) {
    a[i] += inc[idx];
    v2[num++] =
        make_pair((a[i] < 0 ? -b[i] : b[i]), abs((long long)a[i] * b[i]));
    if (a[i] < 0) {
      mx[idx] = max(mx[idx], a[i]);
    }
  }
  inc[idx] = last[idx] = 0;
  sort(v2, v2 + num);
  sz[idx] = 0;
  long long cur;
  for (int i = 0; i < num; i++) {
    while (sz[idx] > 0) {
      cur = get(v[idx][sz[idx] - 1].second.first,
                v[idx][sz[idx] - 1].second.second, v2[i].first, v2[i].second);
      if (cur <= v[idx][sz[idx] - 1].first)
        sz[idx]--;
      else
        break;
    }
    if (sz[idx] == 0)
      v[idx][sz[idx]++] = make_pair(-(long long)1e18, v2[i]);
    else
      v[idx][sz[idx]++] = make_pair(cur, v2[i]);
  }
}
inline long long get(int idx) {
  while (last[idx] + 1 < sz[idx] && v[idx][last[idx] + 1].first <= inc[idx])
    last[idx]++;
  return (long long)v[idx][last[idx]].second.first * (long long)inc[idx] +
         v[idx][last[idx]].second.second;
}
long long res = 0;
inline long long getmax(int l, int r) {
  res = -(long long)1e18;
  for (int i = l / sq; i <= r / sq; i++) {
    if (i * sq >= l && min(n - 1, (i + 1) * sq - 1) <= r) {
      res = max(res, get(i));
      continue;
    }
    for (int j = max(i * sq, l); j <= min(r, min(n - 1, (i + 1) * sq - 1)); j++)
      res = max(res, abs((long long)(a[j] + inc[i]) * (long long)b[j]));
  }
  return res;
}
inline void update(int l, int r, int val) {
  for (int i = l / sq; i <= r / sq; i++) {
    if (i * sq >= l && min(n - 1, (i + 1) * sq - 1) <= r) {
      inc[i] += val;
      if (mx[i] + inc[i] >= 0) build(i);
      continue;
    }
    for (int j = max(i * sq, l); j <= min(r, min(n - 1, (i + 1) * sq - 1)); j++)
      a[j] += val;
    build(i);
  }
}
int main() {
  sq = SQ;
  scanf("%d%d", &n, &q);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &p);
    g[p].push_back(i);
  }
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &y[i]);
  DFS(1);
  for (int i = 0; i < n; i += sq) build(i / sq);
  int t, v, x;
  while (q--) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d", &v, &x);
      update(L[v], R[v], x);
    } else {
      scanf("%d", &v);
      printf("%lld\n", getmax(L[v], R[v]));
    }
  }
  return 0;
}
