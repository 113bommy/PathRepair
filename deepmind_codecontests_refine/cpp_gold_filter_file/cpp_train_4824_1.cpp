#include <bits/stdc++.h>
using namespace std;
const int pri = 1e+9 + 9;
const int MAXN = 1e+5 + 5;
const int oo = 0x7fffffff;
pair<int, int> f[MAXN], p[MAXN];
int L[MAXN], R[MAXN], lef[MAXN], rig[MAXN];
int work(int l, int r) {
  int d = l;
  for (int i = l + 1; i <= r; i++)
    if (p[i].second > p[d].second) d = i;
  if (l < d) L[d] = work(l, d - 1);
  if (r > d) R[d] = work(d + 1, r);
  lef[d] = L[d] ? lef[L[d]] : p[d].first;
  rig[d] = R[d] ? rig[R[d]] : p[d].first;
  return d;
}
void dfs(int first) {
  f[first] = make_pair(0, 0);
  if (L[first] && R[first]) {
    dfs(L[first]);
    dfs(R[first]);
    f[first] = make_pair(max(f[L[first]].first + f[R[first]].second,
                             f[L[first]].second + f[R[first]].first) +
                             1,
                         f[L[first]].first + f[R[first]].first);
    f[first].first = max(f[first].first, f[first].second);
    return;
  }
  if (!L[first] && !R[first]) return;
  if (L[first]) {
    dfs(L[first]);
    f[first] = make_pair(f[L[first]].second + 1, f[L[first]].first);
    f[first].first = max(f[first].first, f[first].second);
    return;
  }
  dfs(R[first]);
  f[first] = make_pair(f[R[first]].second + 1, f[R[first]].first);
  f[first].first = max(f[first].first, f[first].second);
}
pair<int, int> dfs(int d, int l, int r) {
  if (!d) return make_pair(0, -oo);
  if (p[d].first > r) return dfs(L[d], l, r);
  if (p[d].first < l) return dfs(R[d], l, r);
  if (l <= lef[d] && r >= rig[d]) return f[d];
  pair<int, int> f1 = dfs(L[d], l, r), f2 = dfs(R[d], l, r), F;
  F = make_pair(max(f1.first + f2.second, f1.second + f2.first) + 1,
                f1.first + f2.first);
  F.first = max(F.first, F.second);
  return F;
}
int main() {
  int n, m, root, T;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &p[i].first, &p[i].second);
  long long a, b, c, d;
  scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &d);
  for (int i = m + 1; i <= n; i++)
    p[i].first = (a * p[i - 1].first + b) % pri,
    p[i].second = (c * p[i - 1].second + d) % pri;
  sort(p + 1, p + 1 + n);
  root = work(1, n);
  dfs(root);
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    int first, second;
    scanf("%d%d", &first, &second);
    printf("%d\n", dfs(root, first, second).first);
  }
  return 0;
}
