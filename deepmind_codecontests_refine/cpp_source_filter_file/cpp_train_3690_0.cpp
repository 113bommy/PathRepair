#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
struct node {
  int par, sz;
} lab[N];
vector<int> ed[N];
int a[N], n, m, pos[N], vis[N];
int get(int u) { return lab[u].par == u ? u : lab[u].par = get(lab[u].par); }
bool cmp(int x, int y) { return a[x] > a[y]; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  int x, y;
  for (int i = 1; i <= n; ++i)
    cin >> a[i], lab[i].par = i, lab[i].sz = 1, pos[i] = i;
  for (int i = 1; i <= m; ++i) {
    cin >> x >> y;
    ed[x].push_back(y);
    ed[y].push_back(x);
  }
  long long res = 0;
  sort(pos + 1, pos + n + 1, cmp);
  for (int uu = 1; uu <= n; ++uu) {
    int u = pos[uu];
    vis[u] = 1;
    int v;
    for (int i = 0; i < ed[u].size(); ++i) {
      v = ed[u][i];
      if (!vis[v]) continue;
      x = get(u);
      y = get(v);
      if (x != y) {
        lab[y].par = x;
        res += 1LL * (lab[y].sz * lab[x].sz) * a[u];
        lab[x].sz += lab[y].sz;
      }
    }
  }
  long double tmp = res;
  tmp *= 2;
  tmp /= n;
  tmp /= (n - 1);
  cout << fixed << setprecision(6) << tmp;
  return 0;
}
