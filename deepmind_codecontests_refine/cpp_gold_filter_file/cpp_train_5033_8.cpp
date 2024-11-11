#include <bits/stdc++.h>
using namespace std;
struct node {
  long long x, y;
  int id;
  node() {}
  node(long long _x, long long _y, int _id) {
    x = _x;
    y = _y;
    id = _id;
  }
  friend node operator-(const node &a, const node &b) {
    return node(a.x - b.x, a.y - b.y, 0);
  }
  friend long long operator*(const node &a, const node &b) {
    return a.x * b.y - a.y * b.x;
  }
  friend bool operator<(const node &a, const node &b) {
    if (a.x < b.x) return 1;
    if (a.x > b.x) return 0;
    return a.y < b.y;
  }
} a[1555];
node base;
vector<int> g[1555];
int s[1555], n, x, y, ans[1555];
bool cmp(const node &a, const node &b) { return (a - base) * (b - base) > 0; }
void dfs(int id, int fa) {
  s[id] = 1;
  for (vector<int>::iterator ii = g[id].begin(); ii != g[id].end(); ii++)
    if (*ii != fa) {
      dfs(*ii, id);
      s[id] += s[*ii];
    }
}
void solve(int id, int fa, int l, int r) {
  for (int i = l; i < r; i++)
    if (a[i] < a[l]) swap(a[i], a[l]);
  base = a[l];
  sort(a + l + 1, a + r, cmp);
  ans[a[l].id] = id;
  l++;
  for (vector<int>::iterator ii = g[id].begin(); ii != g[id].end(); ii++)
    if (*ii != fa) {
      solve(*ii, id, l, l + s[*ii]);
      l += s[*ii];
    }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    a[i] = node(x, y, i);
  }
  dfs(1, 0);
  solve(1, 0, 0, n);
  for (int i = 0; i < n; i++) !i ? printf("%d", ans[i]) : printf(" %d", ans[i]);
  printf("\n");
  return 0;
}
