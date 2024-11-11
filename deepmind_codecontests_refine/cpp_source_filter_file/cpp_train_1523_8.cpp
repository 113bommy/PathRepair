#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5000 + 20;
int x[MAX_N], y[MAX_N];
int mark[MAX_N];
int n;
bool dfs(int v, int w) {
  bool b = 1;
  for (int u = 0; u < n; u++) {
    if (abs(x[v] - x[u]) + abs(y[v] - y[u]) <= w || u == v) continue;
    if (mark[u] == mark[v]) return 0;
    if (mark[u] == 0) {
      mark[u] = mark[v] * 15;
      b &= dfs(u, w);
    }
  }
  return b;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  int L = -1, R = MAX_N * MAX_N;
  while (R - L > 1) {
    int mid = (L + R) / 2;
    bool b = 1;
    for (int i = 0; i < n; i++)
      if (mark[i] == 0) {
        mark[i] = 1;
        b &= dfs(i, mid);
      }
    memset(mark, 0, sizeof mark);
    if (b)
      R = mid;
    else
      L = mid;
  }
  cout << R << '\n';
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (!mark[i]) {
      ans++;
      mark[i] = 1;
      dfs(i, R);
    }
  int x = 1;
  while (ans--) x *= 2, x %= (int)(1e9 + 7);
  cout << x;
  return 0;
}
