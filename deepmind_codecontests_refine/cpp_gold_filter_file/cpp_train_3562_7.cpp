#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  short negative = 1;
  x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') negative = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  x *= negative;
}
long long qpow(long long n, long long k) {
  long long ans = 1;
  while (k) {
    if (k % 2) {
      ans *= n;
      ans %= 1000000007;
    }
    n *= n;
    n %= 1000000007;
    k /= 2;
  }
  return ans;
}
const int N = 300010;
int n, k;
int sz, x;
char s[N];
int c[N][2];
int cnt[N];
int par[N];
bool st[N];
int st1[N];
vector<int> g[N];
int ans[N];
int fa[N];
int find(int x) {
  if (fa[x] == x) return x;
  fa[x] = find(fa[x]);
  return fa[x];
}
int get(int u) {
  u = find(u);
  if (st1[u] == 1) {
    return g[u].size() - ans[u];
  }
  if (st1[u] == 2) {
    return ans[u];
  }
  return min((int)g[u].size() - ans[u], ans[u]);
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  memset(st1, 0, sizeof(st1));
  for (int i = (1), _b = (n); i <= _b; i++) cin >> s[i];
  for (int i = (1), _b = (k); i <= _b; i++) g[i].push_back(i);
  for (int i = (1), _b = (k); i <= _b; i++) fa[i] = i;
  for (int i = (1), _b = (k); i <= _b; i++) ans[i] = 0;
  for (int i = (1), _b = (k); i <= _b; i++) {
    cin >> sz;
    for (int j = 0, _n = sz; j < sz; j++) {
      cin >> x;
      c[x][cnt[x]++] = i;
    }
  }
  int ans_ = 0;
  for (int i = (1), _b = (n); i <= _b; i++) {
    if (cnt[i] == 0) {
      cout << ans_ << "\n";
      continue;
    }
    if (cnt[i] == 1) {
      if (s[i] == '0') {
        int u = c[i][0];
        int x = find(u);
        ans_ -= get(x);
        if (st[u] == 0)
          st1[x] = 1;
        else
          st1[x] = 2;
        ans_ += get(x);
      } else {
        int u = c[i][0];
        int x = find(u);
        ans_ -= get(x);
        if (st[u] == 0)
          st1[x] = 2;
        else
          st1[x] = 1;
        ans_ += get(x);
      }
    }
    if (cnt[i] == 2) {
      int u = c[i][0], v = c[i][1];
      int x = find(u), y = find(v);
      if (x != y) {
        if (g[x].size() > g[y].size()) swap(u, v), swap(x, y);
        ans_ -= get(x);
        ans_ -= get(y);
        int val = 0;
        if (s[i] == '0') {
          if (st[u] == st[v]) {
            val = 1;
            if (st1[x] != 0) st1[x] ^= 3;
          }
          if (st1[x] != 0) st1[y] = st1[x];
        }
        if (s[i] == '1') {
          if (st[u] != st[v]) {
            val = 1;
            if (st1[x] != 0) st1[x] ^= 3;
          }
          if (st1[x] != 0) st1[y] = st1[x];
        }
        for (int j = 0, _n = g[x].size(); j < g[x].size(); j++) {
          st[g[x][j]] ^= val;
        }
        for (int j = 0, _n = g[x].size(); j < g[x].size(); j++) {
          g[y].push_back(g[x][j]);
          if (st[g[x][j]] == 1) ans[y]++;
        }
        g[x].clear();
        fa[x] = y;
        ans_ += get(y);
      }
    }
    cout << ans_ << "\n";
  }
  return 0;
}
