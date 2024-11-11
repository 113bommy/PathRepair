#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
struct Edge {
  int u, v, w;
} e[N * N];
int n, m;
bitset<N> b[N];
char s[N];
int f[N];
int getf(int v) { return f[v] == v ? v : f[v] = getf(f[v]); }
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) f[i] = i, b[i].reset();
    for (int i = 1; i <= m; i++) {
      cin >> (s + 1);
      for (int j = 1; j <= n; j++)
        if (s[j] == '1') b[i][j] = 1;
    }
    int idx = 0;
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        e[++idx] = {i, j, int((b[i] & b[j]).count())};
    sort(e + 1, e + idx + 1, [](Edge a, Edge b) { return a.w > b.w; });
    vector<pair<int, int>> v2;
    for (int i = 1; i <= idx; i++) {
      if (getf(e[i].u) != getf(e[i].v)) {
        f[getf(e[i].u)] = getf(e[i].v);
        v2.push_back({e[i].u, e[i].v});
      }
    }
    bool ok = 1;
    for (int i = 1; i <= m; i++) {
      int cnt = 0;
      for (int j = 1; j <= n; j++) f[j] = b[j][i] ? j : 0;
      for (auto &j : v2) {
        if (b[j.first][i] && b[j.second][i]) f[getf(j.first)] = j.second;
      }
      for (int i = 1; i <= n; i++) cnt += f[i] == i;
      if (cnt != 1) {
        cout << "NO" << endl;
        ok = 0;
        break;
      }
    }
    if (!ok) continue;
    cout << "YES" << endl;
    for (auto &i : v2) cout << i.first << ' ' << i.second << endl;
  }
  return 0;
}
