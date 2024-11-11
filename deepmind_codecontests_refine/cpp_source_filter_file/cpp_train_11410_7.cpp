#include <bits/stdc++.h>
using namespace std;
vector<int> e[100001];
long long a[100001], f[100001];
int n, s;
void doc() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%i64d", &a[i]);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  scanf("%d", &s);
  s--;
}
void dfs(int u, int cha) {
  vector<pair<long long, long long> > can;
  long long lim = e[u].size();
  for (int i = 0; i < lim; i++) {
    int v = e[u][i];
    if (v != cha) {
      dfs(v, u);
      can.push_back(make_pair(f[v] + 1, v));
    }
  }
  sort(can.rbegin(), can.rend());
  if (u != s) a[u]--;
  f[u] = a[u];
  if (can.size() < f[u]) f[u] = can.size();
  lim = f[u];
  for (int i = 0; i < lim; i++) {
    f[u] += can[i].first;
    a[can[i].second]--;
    a[u]--;
  }
  lim = e[u].size();
  for (int i = 0; i < lim; i++) {
    int v = e[u][i];
    if (v != cha) {
      long long add = min(a[u], a[v]);
      f[u] += 2 * add;
      a[u] -= add;
      a[v] -= add;
    }
  }
  if (u != s) a[u]++;
}
void ghi() { printf("%i64d\n", f[s]); }
int main() {
  doc();
  dfs(s, -1);
  ghi();
  return 0;
}
