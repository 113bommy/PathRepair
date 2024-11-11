#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int g[80][80];
int n, k, a[80], b[80];
int job[80];
int u[80], v[80];
bool used[80];
int dist[80];
int par[80];
void hungarian() {
  for (int i = 1; i <= n; i++) {
    job[0] = i;
    int j0 = 0;
    for (int l = 0; l < 80; l++) {
      used[l] = 0;
      dist[l] = INF;
      par[l] = 79;
    }
    while (job[j0]) {
      used[j0] = 1;
      int i0 = job[j0], d = INF, j1 = 79;
      for (int j = 1; j <= n; j++) {
        if (used[j]) continue;
        int w = g[i0][j] - u[i0] - v[j];
        if (w < dist[j]) {
          dist[j] = w;
          par[j] = j0;
        }
        if (dist[j] < d) {
          d = dist[j];
          j1 = j;
        }
      }
      for (int j = 0; j <= n; j++) {
        if (used[j]) {
          u[job[j]] += d;
          v[j] -= d;
        } else
          dist[j] -= d;
      }
      j0 = j1;
    }
    while (j0) {
      int j1 = par[j0];
      job[j0] = job[j1];
      j0 = j1;
    }
  }
}
void solve() {
  memset(g, 0, sizeof(g));
  memset(u, 0, sizeof(u));
  memset(v, 0, sizeof(v));
  memset(job, 0, sizeof(job));
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    g[1][i] = a[i] + b[i] * (k - 1);
    for (int j = 2; j <= k; j++) {
      g[j][i] = a[i] + (j - 2) * b[i];
    }
    for (int j = k + 1; j <= n; j++) {
      g[j][i] = b[i] * (k - 1);
    }
  }
  for (int i1 = 1; i1 <= n; i1++)
    for (int i2 = 1; i2 <= n; i2++) {
      g[i1][i2] = -g[i1][i2];
    }
  hungarian();
  vector<int> ans;
  for (int idx = 2; idx <= k; idx++) {
    for (int i = 1; i <= n; i++) {
      if (job[i] == idx) ans.push_back(i);
    }
  }
  for (int idx = k + 1; idx <= n; idx++) {
    for (int i = 1; i <= n; i++) {
      if (job[i] == idx) {
        ans.push_back(i);
        ans.push_back(-i);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (job[i] == 1) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for (auto xd : ans) cout << xd << " ";
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
