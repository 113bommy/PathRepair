#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
template <typename T>
void inline read(T &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
  x *= f;
}
template <typename T>
void inline put(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) put(x / 10);
  putchar(x % 10 + '0');
  return;
}
const int maxn = 1e6 + 5;
int n, m, q;
int vis[maxn], sum, qx[maxn], qy[maxn];
int e[maxn], nex[maxn], h[maxn], id;
int fa[maxn], d[maxn], st[maxn];
void add(int x, int y) {
  e[++id] = y;
  nex[id] = h[x];
  h[x] = id;
}
void dfs(int x) {
  st[x] = 1;
  for (int i = h[x]; i; i = nex[i]) {
    int j = e[i];
    if (st[j]) continue;
    d[j] = d[x] + 1;
    fa[j] = x;
    dfs(j);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    add(x, y);
    add(y, x);
  }
  dfs(1);
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int x, y;
    cin >> x >> y;
    qx[i] = x;
    qy[i] = y;
    vis[x]++;
    vis[y]++;
    if (vis[x] % 2)
      sum++;
    else
      sum--;
    if (vis[y] % 2)
      sum++;
    else
      sum--;
  }
  if (sum) {
    cout << "NO" << endl;
    cout << sum / 2 << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (int i = 1; i <= q; i++) {
    int x = qx[i], y = qy[i];
    vector<int> ans1, ans2;
    while (x != y) {
      if (d[x] > d[y])
        ans1.push_back(x), x = fa[x];
      else
        ans2.push_back(y), y = fa[y];
    }
    ans1.push_back(x);
    cout << ans1.size() + ans2.size() << endl;
    for (int j = 0; j < ans1.size(); j++) cout << ans1[j] << " ";
    for (int j = ans2.size() - 1; j >= 0; j--) cout << ans2[j] << " ";
    cout << endl;
  }
}
