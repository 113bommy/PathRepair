#include <bits/stdc++.h>
using namespace std;
int n, m, a[2048], b[2048], g[128][128];
bool dfs(int v, int depth, int f) {
  b[depth] = v;
  if (depth == m) return f;
  for (int i = (f ? 1 : a[depth + 1]); i <= n; i++) {
    if (!g[v][i]) continue;
    g[v][i]--, g[i][v]--;
    if (dfs(i, depth + 1, f | (i > a[depth + 1]))) {
      return 1;
    }
    g[v][i]++, g[i][v]++;
  }
  return 0;
}
int main() {
  cin >> n >> m >> a[0];
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    g[a[i - 1]][a[i]]++;
    g[a[i]][a[i - 1]]++;
  }
  if (dfs(a[0], 0, 0)) {
    for (int i = 0; i <= m; i++) {
      cout << b[i] << " ";
    }
  } else {
    cout << "No solution";
  }
}
