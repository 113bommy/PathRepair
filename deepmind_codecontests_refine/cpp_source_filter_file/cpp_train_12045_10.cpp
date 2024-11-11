#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 1;
int n, m, k, s;
int a, b, x[100];
vector<int> g[maxn];
queue<int> q[200];
int d[200][maxn];
int main() {
  cin >> n >> m >> k >> s;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      d[j][i] = 1e9;
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    q[x[i]].push(i);
    d[x[i]][i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= k; i++) {
    while (!q[i].empty()) {
      int v = q[i].front();
      q[i].pop();
      for (int j : g[v]) {
        if (d[i][j] > d[i][v] + 1) {
          d[i][j] = d[i][v] + 1;
          q[i].push(j);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    vector<int> h;
    h.clear();
    for (int j = 1; j <= k; j++) {
      h.push_back(d[j][i]);
    }
    sort(h.begin(), h.end());
    int ans = 0;
    for (int j = 0; j < s; j++) {
      ans += h[j];
    }
    cout << ans << " ";
  }
}
