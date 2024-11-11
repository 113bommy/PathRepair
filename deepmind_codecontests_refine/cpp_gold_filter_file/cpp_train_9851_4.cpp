#include <bits/stdc++.h>
using namespace std;
int n, m, x[200001], y[200001], parent[200001], v[200001], e[200001], p[200001];
void PreProcess() {
  vector<int> c;
  for (int i = 1; i <= m; ++i) c.push_back(x[i]), c.push_back(y[i]);
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());
  for (int i = 1; i <= m; ++i) {
    x[i] = lower_bound(c.begin(), c.end(), x[i]) - c.begin() + 1;
    y[i] = lower_bound(c.begin(), c.end(), y[i]) - c.begin() + 1;
  }
  n = c.size();
  for (int i = 1; i <= n; ++i) parent[i] = i, v[i] = 1, e[i] = 0;
  p[0] = 1;
  for (int i = 1; i <= n; ++i) p[i] = (2 * p[i - 1]) % 1000000007;
}
int Find(int i) {
  if (i == parent[i])
    return i;
  else
    return (parent[i] = Find(parent[i]));
}
void Union(int i, int j) {
  i = Find(i), j = Find(j);
  if (i > j) swap(i, j);
  if (i == j)
    ++e[i];
  else {
    v[i] += v[j];
    e[i] += (1 + e[j]);
    parent[j] = i;
  }
}
int main() {
  long long ans = 1;
  scanf("%d", &m);
  for (int k = 1; k <= m; ++k) {
    int i, j;
    scanf("%d%d", &i, &j);
    i = i + i, j = j + j + 1;
    x[k] = i, y[k] = j;
  }
  PreProcess();
  for (int k = 1; k <= m; ++k) Union(x[k], y[k]);
  for (int i = 1; i <= n; ++i) {
    if (Find(i) != i) continue;
    if (e[i] >= v[i])
      ans = (ans * p[v[i]]) % 1000000007;
    else
      ans = (ans * (p[v[i]] + 1000000007 - 1)) % 1000000007;
  }
  printf("%lld\n", ans);
  return 0;
}
