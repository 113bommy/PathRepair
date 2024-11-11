#include <bits/stdc++.h>
using namespace std;
int n;
int p[105], d[105], par[105];
vector<int> a[105], b[105];
int findpar(int u) { return par[u] == u ? u : par[u] = findpar(par[u]); }
void merge(int v, int u) { par[findpar(u)] = findpar(v); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) par[i] = i;
  for (int i = 1; i <= n; i++) scanf("%d", p + i);
  for (int i = 1; i <= n; i++) scanf("%d", d + i);
  for (int i = 1; i <= n; i++) {
    if (i + d[i] <= n) merge(i, i + d[i]);
    if (i - d[i] > 0) merge(i, i - d[i]);
  }
  for (int i = 1; i <= n; i++) {
    a[findpar(i)].push_back(i);
    b[findpar(i)].push_back(p[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (a[i].size()) {
      sort(a[i].begin(), a[i].end());
      sort(b[i].begin(), b[i].end());
      for (int j = 0; j < a[i].size(); j++) {
        if (a[j] != b[j]) return 0 * printf("NO");
      }
    }
  }
  puts("YES");
  return 0;
}
