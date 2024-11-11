#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
struct node {
  int t, l, r;
  node(int t = 0, int l = 0, int r = 0) : t(t), l(l), r(r) {}
  friend bool operator<(node a, node b) {
    if (a.r == b.r) {
      if (a.l == b.l) return a.t == 1;
      return a.l < b.l;
    }
    return a.r < b.r;
  }
} p[maxn];
vector<node> v1, v0;
int ans[maxn];
int n, m;
int f[maxn];
void init() {
  for (int i = 1; i <= n; i++) f[i] = i;
}
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int main() {
  cin >> n >> m;
  init();
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &p[i].t, &p[i].l, &p[i].r);
    if (p[i].t == 1)
      v1.push_back(p[i]);
    else
      v0.push_back(p[i]);
  }
  sort(v1.begin(), v1.end());
  for (int i = 0; i < v1.size(); i++) {
    for (int j = v1[i].l + 1; j <= v1[i].r; ++j) f[j] = j - 1;
  }
  bool ok = 1;
  sort(v0.begin(), v0.end());
  for (auto v : v0) {
    bool tmp = 0;
    for (int i = v.l + 1; i <= v.r; i++) {
      if (find(i) != find(i - 1)) {
        tmp = 1;
        break;
      }
    }
    if (!tmp) {
      ok = 0;
      break;
    }
  }
  if (!ok) {
    cout << "NO";
    return 0;
  }
  int lim = 1e6;
  cout << "YES\n";
  ans[1] = lim;
  for (int i = 2; i <= n; i++) {
    if (find(i) == find(i - 1)) {
      ans[i] = ans[i - 1] + 1;
    } else
      ans[i] = ans[i - 1] - 1;
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
