#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int INF = 2147483647;
const int INF2 = 0x3f3f3f3f;
const long long INF64 = 4e18;
const double INFD = 1e30;
const double EPS = 1e-10;
const long double PI = acosl(-1);
const int MOD = 1e9 + 7;
template <typename T>
inline T read() {
  T X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
const int MAXN = 3005;
const int MAXV = 60;
int n, m, k;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int dr2[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dc2[8] = {1, 0, -1, 1, 0, -1, 1, -1};
int CASE = 1;
struct Inv {
  int l, r, id;
  bool operator<(const Inv& a) const { return r < a.r; }
};
Inv invs[MAXN];
int cnt[MAXN], f[MAXN];
vector<int> G[MAXN];
bool vis[MAXN];
int N;
struct FenwickTree {
  FenwickTree() {}
  inline void increase(int t, int x) {
    for (int i = t; i <= N; i += lowbit(i)) _arr[i] = max(_arr[i], x);
  }
  inline int getSum(int t) {
    int s = 0;
    for (int i = t; i; i -= lowbit(i)) s = max(s, _arr[i]);
    return s;
  }
  void clear() {
    for (int i = 1; i <= N; i++) _arr[i] = 0;
  }
  int _arr[MAXN * 3];
  inline int lowbit(int x) { return x & (-x); }
};
template <typename T>
struct Discretization {
  vector<T> xp;
  int size() const { return xp.size(); }
  void add(T val) { xp.push_back(val); }
  void discretize() {
    sort(xp.begin(), xp.end());
    xp.resize(unique(xp.begin(), xp.end()) - xp.begin());
  }
  int get(T val) {
    return lower_bound(xp.begin(), xp.end(), val) - xp.begin() + 1;
  }
  void clear() { xp.clear(); }
  T get2(int num) { return xp[num - 1]; }
};
FenwickTree tree;
Discretization<int> discrete;
void dfs(int x) {
  if (vis[x]) return;
  vis[x] = true;
  if (G[x].empty()) return;
  for (auto v : G[x]) dfs(v);
  sort(G[x].begin(), G[x].end(),
       [](int a, int b) { return invs[a].r < invs[b].r; });
  int sz = G[x].size(), num = 0;
  for (int i = 0; i < sz; i++) {
    f[i] = cnt[G[x][i]] + tree.getSum(invs[G[x][i]].l - 1);
    tree.increase(invs[G[x][i]].r, f[i]);
    num = max(num, f[i]);
  }
  tree.clear();
  cnt[x] = num + 1;
}
void solve() {
  scanf("%d", &n);
  discrete.clear();
  for (int i = 1; i <= n; i++) {
    invs[i].l = read<int>();
    invs[i].r = read<int>();
    invs[i].id = i;
    cnt[i] = 1;
    vis[i] = false;
    G[i].clear();
    discrete.add(invs[i].l);
    discrete.add(invs[i].r);
  }
  discrete.discretize();
  N = discrete.size();
  for (int i = 1; i <= n; i++) {
    invs[i].l = discrete.get(invs[i].l);
    invs[i].r = discrete.get(invs[i].r);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j && invs[i].l >= invs[j].l && invs[i].r <= invs[j].r) {
        G[j].push_back(i);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i);
  }
  int ans = 0;
  sort(invs + 1, invs + n + 1);
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    f[i] = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (invs[j].r < invs[i].l) {
        f[i] = max(f[i], cnt[invs[i].id] + f[j]);
      }
    }
    ans = max(ans, f[i]);
  }
  printf("%d\n", ans);
}
int main() {
  int T = read<int>();
  while (T--) {
    solve();
  }
  return 0;
}
