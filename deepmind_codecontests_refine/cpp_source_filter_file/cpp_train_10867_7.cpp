#include <bits/stdc++.h>
using namespace std;
const int N = 101;
const int INF = (int)1e9;
int n, d, a[N];
int inQ[N], maxT[N];
struct point {
  int x, y;
} f[N];
queue<int> q;
int dist(point a, point b) { return abs(a.x - b.x) + abs(a.y - b.y); }
bool check(int mid) {
  for (int i = 1; i <= n; ++i) {
    maxT[i] = -INF;
  }
  maxT[1] = mid + a[1];
  q.push(1), inQ[1] = 1;
  while (q.size()) {
    int u = q.front();
    q.pop();
    inQ[u] = 0;
    for (int v = 1; v <= n; ++v) {
      if (v == u || d * dist(f[u], f[v]) > maxT[u]) continue;
      if (maxT[v] < maxT[u] - d * dist(f[u], f[v]) + a[v]) {
        maxT[v] = maxT[u] - d * dist(f[u], f[v]) + a[v];
        if (!inQ[v]) {
          q.push(v);
          inQ[v] = 1;
        }
      }
    }
  }
  return maxT[n] >= 0;
}
void solve() {
  cin >> n >> d;
  for (int i = 2; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) cin >> f[i].x >> f[i].y;
  int l = 0, r = (int)2e7, res = r;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      res = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
