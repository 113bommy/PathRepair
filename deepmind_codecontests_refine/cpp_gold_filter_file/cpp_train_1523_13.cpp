#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 1e9 + 7;
int x[MAXN], y[MAXN], colors[MAXN], n;
int calc(int u, int v) { return abs(x[u] - x[v]) + abs(y[u] - y[v]); }
bool dfs(int start, int color, int mid) {
  bool val = true;
  colors[start] = color;
  for (int u = 0; u < n; ++u) {
    int distance = calc(start, u);
    if (distance <= mid) continue;
    if (colors[u] == 0) {
      bool newRes = dfs(u, 3 - color, mid);
      val &= newRes;
    } else {
      if (colors[u] == color) val = false;
    }
  }
  return val;
}
pair<bool, int> check(int mid) {
  for (int i = 0; i < n + 1; ++i) colors[i] = 0;
  int res = 1;
  for (int i = 0; i < n; ++i) {
    if (colors[i] == 0) {
      bool value = dfs(i, 1, mid);
      if (!value) return {false, 0};
      res *= 2;
      res %= INF;
    }
  }
  return {true, res};
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  int l = -1, r = 100000;
  while (r - l > 1) {
    int mid = l + (r - l) / 2;
    if (check(mid).first)
      r = mid;
    else
      l = mid;
  }
  cout << r << endl;
  cout << check(r).second;
}
