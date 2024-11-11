#include <bits/stdc++.h>
using namespace std;
int parent[200005], size[200005];
struct edge {
  int x, y, val;
  bool operator<(const edge& e) const { return val < e.val; }
} a[200005];
struct query {
  int id, val;
  bool operator<(const query& q) const { return val < q.val; }
} q[200005];
int res[200005];
int find(int p) {
  if (p == parent[p]) return p;
  return parent[p] = find(parent[p]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
    size[i] = 1;
  }
  for (int i = 1; i < n; i++) {
    cin >> a[i].x >> a[i].y >> a[i].val;
  }
  sort(a + 1, a + n);
  for (int i = 1; i <= m; i++) {
    cin >> q[i].val;
    q[i].id = i;
  }
  sort(q + 1, q + 1 + m);
  int index = 1;
  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    while (index < n && a[index].val <= q[i].val) {
      int x = a[index].x;
      int y = a[index].y;
      int rootx = find(x);
      int rooty = find(y);
      ans += (long long)size[rootx] * size[rooty];
      size[rootx] += size[rooty];
      parent[rooty] = rootx;
      index++;
    }
    res[q[i].id] = ans;
  }
  for (int i = 1; i <= m; i++) {
    cout << res[i];
    if (i == m)
      cout << '\n';
    else
      cout << ' ';
  }
  return 0;
}
