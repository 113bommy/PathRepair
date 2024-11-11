#include <bits/stdc++.h>
using namespace std;
const int dx44[5] = {0, -1, -1, 1, 1};
const int dy44[5] = {0, -1, 1, -1, 1};
const int dx4[5] = {0, -1, 0, 1, 0};
const int dy4[5] = {0, 0, 1, 0, -1};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int maxn = 2e5 + 5;
const double PI = acos(-1.0);
const long long mod = 1e9 + 7;
long long po(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
}
void YES() {
  puts("YES");
  exit(0);
}
void Yes() { puts("Yes"); }
void NO() {
  puts("NO");
  exit(0);
}
void No() { puts("No"); }
void one() {
  puts("-1");
  exit(0);
}
int n;
int cnt;
int vx[maxn], vy[maxn];
int vis[maxn];
vector<int> edge[maxn];
map<pair<int, int>, int> hax;
int L, P;
void dfs(int x) {
  vis[x] = 1;
  L++;
  for (int i = 0; i < edge[x].size(); i++) {
    int nxt = edge[x][i];
    P++;
    if (vis[nxt]) continue;
    dfs(nxt);
  }
}
void solve() {
  scanf("%d", &(n));
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &(vx[i])), scanf("%d", &(vy[i]));
    if (!hax.count(make_pair(vx[i], 0))) {
      ++cnt;
      hax[make_pair(vx[i], 0)] = cnt;
    }
    int u = hax[make_pair(vx[i], 0)];
    if (!hax.count(make_pair(vy[i], 1))) {
      ++cnt;
      hax[make_pair(vy[i], 1)] = cnt;
    }
    int v = hax[make_pair(vy[i], 1)];
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  long long ans = 1;
  for (int i = 1; i <= cnt; i++) {
    if (vis[i]) continue;
    L = 0, P = 0;
    dfs(i);
    P /= 2;
    if (P == L - 1) {
      ans = ans * (po(2, L, mod) - 1 + mod) % mod;
    } else {
      ans = ans * po(2, P, mod) % mod;
    }
    ans %= mod;
  }
  printf("%lld\n", ans);
}
int main() {
  solve();
  return 0;
}
