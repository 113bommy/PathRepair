#include <bits/stdc++.h>
using namespace std;
struct Point {
  long long x, y;
  Point() {}
  Point(int _x, int _y) {
    x = _x;
    y = _y;
  }
};
Point p[100000];
int n, q;
int st[100000];
int pt = 0;
vector<int> g[100000];
int pr[100000][20];
int tin[100000];
int tout[100000];
int timer = 0;
void dfs(int curr, int anc) {
  pr[curr][0] = anc;
  tin[curr] = timer++;
  for (int i = 1; i < 20; i++) {
    pr[curr][i] = pr[pr[curr][i - 1]][i - 1];
  }
  for (int i = 0; i < g[curr].size(); i++) {
    int to = g[curr][i];
    if (to == anc) continue;
    dfs(to, curr);
  }
  tout[curr] = timer++;
}
bool isAnc(int v1, int v2) {
  return tin[v1] <= tin[v2] && tout[v1] >= tout[v2];
}
int lca(int v1, int v2) {
  if (isAnc(v1, v2)) return v1;
  if (isAnc(v2, v1)) return v2;
  int curr = v2;
  for (int i = 19; i >= 0; i--) {
    if (!isAnc(pr[curr][i], v1)) curr = pr[curr][i];
  }
  return pr[curr][0];
}
bool bad(Point& a, Point& b, Point& c) {
  return (a.x - b.x) * (c.y - b.y) - (c.x - b.x) * (a.y - b.y) <= 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    p[i].x = x;
    p[i].y = y;
  }
  for (int i = n - 1; i >= 0; i--) {
    while (pt >= 2 && bad(p[i], p[st[pt - 1]], p[st[pt - 2]])) pt--;
    if (i != n - 1) {
      g[i].push_back(st[pt - 1]);
      g[st[pt - 1]].push_back(i);
    }
    st[pt++] = i;
  }
  dfs(n - 1, n - 1);
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    r--;
    l--;
    cout << lca(l, r) + 1 << " ";
  }
  return 0;
}
