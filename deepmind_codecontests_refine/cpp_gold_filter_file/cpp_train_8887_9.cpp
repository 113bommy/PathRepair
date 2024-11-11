#include <bits/stdc++.h>
int diri[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dirj[] = {0, 1, 0, -1, 1, 1, -1, -1};
int compare(double d1, double d2) {
  if (fabs(d1 - d2) < 1e-9) return 0;
  if (d1 < d2) return -1;
  return 1;
}
using namespace std;
int x[501];
int y[501];
int ln[501];
int used[501];
int vis[501];
int n, m;
int main() {
  cin >> n >> m;
  for (int i = 0; i < (int)n; i++) cin >> x[i] >> y[i];
  for (int i = 0; i < (int)m; i++) cin >> ln[i];
  bool b = 0;
  for (int i = 0; i < 2; ++i) {
    memset(used, -1, sizeof(used));
    memset(vis, 0, sizeof(vis));
    int j;
    for (j = i; j < n; j += 2) {
      int a = (j + 1) % n;
      int b = (j + n - 1) % n;
      int dist1 = abs(x[a] - x[j] ? (x[a] - x[j]) : (y[a] - y[j]));
      int dist2 = abs(x[b] - x[j] ? (x[b] - x[j]) : (y[b] - y[j]));
      int k;
      for (k = 0; k < m; ++k)
        if (!vis[k] && ln[k] == dist1 + dist2) break;
      if (k == m) break;
      vis[k] = true;
      used[j] = k + 1;
    }
    if (j >= n) {
      b = 1;
      break;
    }
  }
  if (b) {
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) cout << used[i] << " ";
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
