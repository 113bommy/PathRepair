#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
inline int add(int a, int b) {
  if ((a += b) >= mod) a -= mod;
  return a;
}
inline int mult(int a, int b) {
  long long t = 1ll * a * b;
  if (t >= mod) t %= mod;
  return t;
}
int n, deg[200010], siz[200010], dep[200010], ch[200010], c1[200010],
    c2[200010];
vector<int> v[200010];
int K[200010], dp[200010];
map<pair<int, int>, int> mp;
inline int count_2(int u, int v) {
  while (1) {
    if (!u && !v) return 1;
    if (!u || !v) return dp[u | v];
    if (ch[u] == 2 || ch[v] == 2) return 0;
    u = c1[u];
    v = c1[v];
  }
}
inline bool isline(int u, int l) { return (!K[u] && siz[u] == l); }
inline int query(int u, int v) {
  if (u > v) swap(u, v);
  if (!u) return dp[v];
  if (mp.find(make_pair(u, v)) == mp.end()) mp[make_pair(u, v)] = count_2(u, v);
  return mp[make_pair(u, v)];
}
int DP(int p) {
  if (siz[p] & 1) return 0;
  int ret = 0;
  if (ch[p] == 2) {
    int x = c1[p], y = c2[p];
    if (ch[x] != 2) ret = add(ret, count_2(c1[x], y));
    if (ch[y] != 2) ret = add(ret, count_2(c1[y], x));
    return ret;
  }
  int P = K[p];
  if (!P) return siz[p] / 2;
  int ds = dep[P] - dep[p];
  if (ds >= 2) ret = add(ret, dp[ch[ch[p]]]);
  int x = c1[P], y = c2[P];
  if (isline(x, ds - 1)) ret = add(ret, dp[y]);
  if (isline(y, ds - 1)) ret = add(ret, dp[x]);
  for (int i = 0; i < 2; i++) {
    swap(x, y);
    if (isline(c1[x], ds)) ret = add(ret, query(c2[x], y));
    if (isline(c2[x], ds)) ret = add(ret, query(c1[x], y));
  }
  return ret;
}
void pre(int np, int fath) {
  siz[np] = 1;
  for (int &x : v[np]) {
    if (x == fath) continue;
    dep[x] = dep[np] + 1;
    pre(x, np);
    ch[np]++;
    if (ch[np] == 1) c1[np] = x;
    if (ch[np] == 2) c2[np] = x;
    siz[np] += siz[x];
  }
  K[np] = (ch[np] < 2) ? K[c1[np]] : np;
  dp[np] = DP(np);
}
int solve(int np) {
  int ans = 0;
  pre(np, 0);
  int s[3] = {0}, st = 0;
  for (int &x : v[np]) s[st++] = x;
  sort(s, s + 3);
  do {
    int ts[2] = {0}, tst = 0;
    for (int &x : v[s[1]])
      if (x != np) ts[tst++] = x;
    sort(ts, ts + 2);
    do {
      int sz = siz[s[0]] + siz[ts[0]];
      if (!(sz & 1))
        ans = add(ans, mult(count_2(s[0], ts[0]), count_2(s[2], ts[1])));
    } while (next_permutation(ts, ts + 2));
  } while (next_permutation(s, s + 3));
  return ans;
}
int main() {
  scanf("%d", &n);
  n <<= 1;
  for (int i = 1, a, b; i < n; i++) {
    scanf("%d%d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
    deg[a]++;
    deg[b]++;
  }
  int rt = 0;
  for (int i = 1; i <= n; i++) {
    if (deg[i] > 3) {
      puts("0");
      return 0;
    }
    if (deg[i] == 3) rt = i;
  }
  if (!rt) {
    n >>= 1;
    if (n == 1)
      puts("2");
    else
      printf("%d\n", mult(2, add(mult(n - 2, n - 1), mult(n, 2))));
  } else {
    printf("%d\n", mult(2, solve(rt)));
  }
  return 0;
}
