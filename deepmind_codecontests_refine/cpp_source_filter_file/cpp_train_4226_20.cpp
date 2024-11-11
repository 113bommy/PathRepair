#include <bits/stdc++.h>
using namespace std;
const int N = 50002;
int n, m, G, S, parent[N], comps;
int x[N], y[N], g[N], second[N];
int v[N], e[N], tmp[N], ne;
int find(int a) { return a == parent[a] ? a : parent[a] = find(parent[a]); }
int main() {
  cin >> n >> m >> G >> S;
  for (int i = 1; i <= m; ++i)
    scanf("%d %d %d %d", x + i, y + i, g + i, second + i), v[i] = i;
  sort(v + 1, v + 1 + m, [](int i, int j) { return g[i] < g[j]; });
  long long ans = 1000000000000000000ll;
  for (int i = 1; i <= m; ++i) {
    int idx = v[i];
    e[++ne] = idx;
    int j = ne;
    while (j > 1 and second[e[j - 1]] > second[e[j]]) swap(e[j - 1], e[j]), --j;
    if (ne < n - 1) continue;
    for (int j = 1; j <= n; ++j) parent[j] = j;
    int mx = 0, cnt = 0;
    for (int j = 1; j <= ne; ++j) {
      int a = x[e[j]], b = y[e[j]], c = second[e[j]];
      if (find(a) != find(b))
        parent[find(a)] = find(b), mx = c, tmp[++cnt] = e[j];
      if (cnt == n - 1) break;
    }
    ne = cnt;
    for (int j = 1; j <= ne; ++j) e[j] = tmp[j];
    if (cnt == n - 1) ans = min(ans, 1ll * g[idx] * G + 1ll * mx * S);
  }
  cout << (ans == 1000000000000000000ll ? -1 : ans);
}
