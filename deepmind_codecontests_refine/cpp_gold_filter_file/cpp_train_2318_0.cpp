#include <bits/stdc++.h>
using namespace std;
const int N = 1000100;
const int K = 21;
int x[K];
int y[K];
int a[N];
int b[N];
int suf[N];
int X[N];
int pos[K];
int z[K];
int dist[(1 << K)];
int par[(1 << K)];
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    char c;
    cin >> c;
    x[i] = c - '0';
  }
  for (int i = 1; i <= k; i++) {
    pos[i] = i;
    char c;
    cin >> c;
    y[i] = c - '0';
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = n; i >= 1; i--) {
    swap(pos[a[i]], pos[b[i]]);
    for (int j = 1; j <= k; j++) {
      if (x[j]) suf[i] ^= (1 << (pos[j] - 1));
    }
  }
  for (int i = 1; i <= k; i++) pos[i] = i;
  int res = k, L = 1, R = 1;
  for (int i = n; i >= 1; i--) {
    int cur = 0;
    for (int j = 1; j <= k; j++) {
      if (y[j]) cur ^= (1 << (pos[j] - 1));
    }
    X[i] = cur;
    swap(pos[a[i]], pos[b[i]]);
  }
  for (int i = 0; i < (1 << k); i++) {
    par[i] = -1;
    dist[i] = 10000001;
  }
  for (int i = m; i <= n; i++) {
    int cur = suf[i - m + 1];
    dist[cur] = 0;
    par[cur] = i - m + 1;
    queue<int> q;
    q.push(cur);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int i = 0; i < k; i++) {
        int to = (v ^ (1 << i));
        if (dist[to] > dist[v] + 1) {
          par[to] = par[v];
          dist[to] = dist[v] + 1;
          q.push(to);
        }
      }
    }
    if (dist[X[i]] < res) {
      res = dist[X[i]];
      L = par[X[i]], R = i;
    }
  }
  cout << k - res << '\n';
  cout << L << " " << R << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
