#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
vector<pair<long long, int> > G[maxn];
set<pair<int, int> > S;
int son[maxn], sz[maxn], f[maxn], col[maxn], ll[maxn], rr[maxn], no[maxn],
    ans[maxn], M[maxn];
int tree[maxn * 4];
int n, tot;
long long ANS = 0;
void dfs0(int x, int fa) {
  sz[x] = 1;
  for (auto e : G[x]) {
    if (e.first == fa) continue;
    dfs0(e.first, x);
    sz[x] += sz[e.first];
    son[x] = max(son[x], sz[e.first]);
  }
  son[x] = max(son[x], n - sz[x]);
}
void dfs(int x, int fa, long long v) {
  sz[x] = 1;
  for (auto e : G[x]) {
    if (e.first == fa) continue;
    dfs(e.first, x, e.second + v);
    sz[x] += sz[e.first];
  }
  ANS += v;
}
void Insert(int o, int l, int r, int k, int v) {
  if (l == r) {
    tree[o] = v;
    return;
  }
  int mid = (l + r) >> 1;
  if (k <= mid)
    Insert(o * 2, l, mid, k, v);
  else
    Insert(o * 2 + 1, mid + 1, r, k, v);
  tree[o] = min(tree[o * 2], tree[o * 2 + 1]);
}
int Query(int o, int l, int r, int L, int R) {
  if (L <= l && r <= R) return tree[o];
  int mid = (l + r) >> 1, ans = 1e9;
  if (L <= mid) ans = min(ans, Query(o * 2, l, mid, L, R));
  if (R > mid) ans = min(ans, Query(o * 2 + 1, mid + 1, r, L, R));
  return ans;
}
void dfs1(int x, int fa, int cc) {
  f[x] = ++tot;
  col[x] = cc;
  Insert(1, 1, n, tot, x);
  for (auto e : G[x]) {
    if (e.first == fa) continue;
    dfs1(e.first, x, cc);
  }
}
void Erase(int col) {
  pair<int, int> x = make_pair(-M[col] - no[col], col);
  S.erase(x);
  if (x.first + 1 < 0) S.insert({x.first + 1, col});
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    G[x].push_back({y, w});
    G[y].push_back({x, w});
  }
  int X;
  dfs0(1, 1);
  for (int i = 1; i <= n; i++)
    if (son[i] <= n / 2) X = i;
  dfs(X, X, 0);
  cout << ANS * 2 << endl;
  int flag = 0, N = 0;
  for (auto e : G[X]) {
    ll[++N] = tot + 1;
    dfs1(e.first, X, N);
    rr[N] = tot;
    S.insert({-2 * sz[e.first], N});
    M[N] = no[N] = sz[e.first];
  }
  f[X] = ++tot;
  Insert(1, 1, n, tot, X);
  ll[++N] = tot;
  rr[N] = tot;
  col[X] = N;
  S.insert({0, N});
  M[N] = no[N] = 1;
  int l, r;
  for (int i = 1; i <= n; i++) {
    auto x = *S.begin();
    int rem = n - i + 1;
    if (col[i] != x.second) {
      rem--;
      if (rem < -x.first) {
        l = ll[x.second], r = rr[x.second];
        int y = Query(1, 1, n, l, r);
        ans[i] = y;
        Erase(x.second);
        M[x.second]--;
        Insert(1, 1, n, f[y], 1e9);
        Erase(col[i]);
        no[col[i]]--;
        continue;
      }
    }
    l = ll[col[i]], r = rr[col[i]];
    int y = 1e9;
    if (l - 1 > 0) y = min(y, Query(1, 1, n, 1, l - 1));
    if (r + 1 <= n) y = min(y, Query(1, 1, n, r + 1, n));
    if (f[i] == n) y = min(i, y);
    Insert(1, 1, n, f[y], 1e9);
    ans[i] = y;
    Erase(col[i]);
    no[col[i]]--;
    Erase(col[y]);
    M[col[y]]--;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
