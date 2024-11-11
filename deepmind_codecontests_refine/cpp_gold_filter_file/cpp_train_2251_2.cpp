#include <bits/stdc++.h>
using namespace std;
int n, k, j, u, mx, nv, V, a[222][33333], d[222][33333], F[33333], rt[222];
vector<pair<int, int> > E[33333];
bool v[33333];
int main() {
  scanf("%d", &n);
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++)
      if (scanf("%d", &a[i][j]), !a[i][j]) rt[i] = j;
    if (!rt[i]) return puts("-1"), 0;
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++)
      if (a[1][j] + a[i][j] == a[1][rt[i]]) d[i][a[1][j]] = j, v[j] = 1;
    for (int j = 1; j <= a[1][rt[i]]; j++) {
      if (!d[i][j]) return puts("-1"), 0;
      F[d[i][j]] = d[i][j - 1];
    }
  }
  for (int i = 1; i <= n; i++)
    if (!v[i]) {
      u = rt[1];
      mx = 0;
      for (int j = 1; j <= k; j++) {
        V = (a[1][rt[j]] - a[j][i] + a[1][i]) / 2;
        if (V > mx) mx = V, u = d[j][V];
      }
      E[u].push_back(make_pair(a[1][i], i));
    }
  for (int i = 1; i <= n; i++) {
    sort(E[i].begin(), E[i].end());
    for (j = 0, nv = a[1][u = i]; j < E[i].size();) {
      if (++nv != E[i][j].first) return puts("-1"), 0;
      for (; j < E[i].size() && E[i][j].first == nv; j++) F[E[i][j].second] = u;
      u = E[i][j - 1].second;
    }
  }
  for (int i = 1; i <= n; i++)
    if (F[i]) printf("%d %d\n", F[i], i);
}
