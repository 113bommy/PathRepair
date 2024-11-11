#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll read() {
  ll x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const ll N = 1e5 + 10;
ll n, root, sz[N], c[N], f[N];
ll k, mn, mx;
struct edge {
  ll y, next;
} a[N * 2];
ll len, last[N];
inline void ins(ll x, ll y) {
  a[++len] = (edge){y, last[x]};
  last[x] = len;
}
inline void dfs(ll x, ll fa) {
  sz[x] = f[x] = 1;
  for (ll k = last[x], y; k; k = a[k].next)
    if ((y = a[k].y) ^ fa) {
      dfs(y, x);
      sz[x] += sz[y];
      f[x] = f[x] > sz[y] ? f[x] : sz[y];
      mn += sz[y] & 1;
      mx += min(sz[y], n - sz[y]);
    }
  f[x] = f[x] > n - sz[x] ? f[x] : n - sz[x];
}
inline void DFS(ll x, ll fa) {
  sz[x] = 1;
  for (ll k = last[x], y; k; k = a[k].next)
    if ((y = a[k].y) ^ fa) {
      DFS(y, x);
      sz[x] += sz[y];
    }
  c[sz[x]]++;
}
ll son[N], tot, A[N], B[N];
vector<ll> d[N];
inline void solve(ll x, ll fa) {
  sz[x] = 1;
  for (ll k = last[x], y; k; k = a[k].next)
    if ((y = a[k].y) ^ fa) {
      solve(y, x);
      sz[x] += c[y];
    }
  son[tot = 1] = x;
  d[x].push_back(x);
  for (ll k = last[x], y; k; k = a[k].next)
    if ((y = a[k].y) ^ fa) son[++tot] = y;
  ll st = 1, ed = tot, tt = (sz[x] - c[x]) / 2;
  for (ll i = 1; i <= tt; i++) {
    while (d[son[st]].empty()) st++;
    A[i] = d[son[st]].back();
    d[son[st]].pop_back();
    while (d[son[ed]].empty()) ed--;
    B[i] = d[son[ed]].back();
    d[son[ed]].pop_back();
  }
  for (ll i = 1; i <= tt; i++) printf("%lld %lld\n", A[i], B[tt - i + 1]);
  for (ll i = st > 2 ? st : 2; i <= ed; i++) {
    if (d[son[i]].size() > d[x].size()) swap(d[son[i]], d[x]);
    for (ll j : d[son[i]]) d[x].push_back(j);
  }
}
int main() {
  n = read();
  k = read();
  for (ll i = 1, x, y; i < n; i++) {
    x = read();
    y = read();
    ins(x, y);
    ins(y, x);
  }
  dfs(1, 0);
  root = 1;
  for (ll i = 2; i <= n; i++)
    if (f[i] < f[root]) root = i;
  if (!(mn <= k && k <= mx) || (k - mn) & 1) {
    puts("NO");
    exit(0);
  }
  DFS(root, 0);
  ll p = n - 1;
  for (; p > 1; p--)
    if (mx - 2 * c[p] >= k) {
      mx -= 2 * c[p];
      c[p - 2] += c[p];
    } else
      break;
  for (ll i = 1; i <= n; i++) c[i] = min(sz[i], p - (p + sz[i]) % 2);
  c[root] = 0;
  for (ll i = 1; i <= n; i++)
    if (c[i] == p && mx > k) {
      c[i] -= 2;
      mx -= 2;
    }
  puts("YES");
  solve(root, 0);
  return 0;
}
