#include <bits/stdc++.h>
using namespace std;
const long N = 3e5 + 1;
vector<long> g[N];
bool c[N];
bool vis[N];
long x, y;
bool found;
long size(long vtx) {
  long sum = 1;
  vis[vtx] = true;
  for (long v : g[vtx]) {
    if (!vis[v] && !c[v]) {
      sum += size(v);
    }
  }
  return sum;
}
void color(long vtx) {
  if (vtx == y) {
    c[vtx] = true;
    found = true;
    return;
  }
  vis[vtx] = true;
  for (long v : g[vtx]) {
    if (!vis[v]) {
      color(v);
      if (found) {
        c[v] = true;
        return;
      }
    }
  }
}
int main() {
  long n;
  cin >> n >> x >> y;
  for (long i = 1; i < n; i++) {
    long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  color(y);
  long sy = size(y);
  for (long i = 1; i <= n; i++) {
    vis[i] = false;
  }
  long sx = size(x);
  cout << 1LL * n * (n - 1) - 1LL * sx * sy;
  return 0;
}
