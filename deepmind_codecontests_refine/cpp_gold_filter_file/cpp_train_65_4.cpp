#include <bits/stdc++.h>
using namespace std;
long long sqr(long long x) { return x * x; }
int mysqrt(long long x) {
  int l = 0, r = 1e9 + 1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (m * (long long)m <= x)
      l = m;
    else
      r = m;
  }
  return l;
}
mt19937 rnd(1227);
mt19937_64 rndll(12365);
long long AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MODR = 1e9 + 993;
long long myrand() {
  long long ZR = (XR * AR + YR * BR + CR) % MODR;
  XR = YR;
  YR = ZR;
  return ZR;
}
const int Mod = 1e9 + 9;
int bpow(int x, int y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  int ret = bpow(x, y >> 1);
  ret = (ret * (long long)ret) % Mod;
  if (y & 1) ret = (ret * (long long)x) % Mod;
  return ret;
}
int bdiv(int x, int y) { return (x * (long long)bpow(y, Mod - 2)) % Mod; }
void setmin(int &x, int y) { x = min(x, y); }
void setmax(int &x, int y) { x = max(x, y); }
void setmin(long long &x, long long y) { x = min(x, y); }
void setmax(long long &x, long long y) { x = max(x, y); }
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
const long long llinf = 2e18 + 100;
const double eps = 1e-9;
const int maxn = 2e5 + 100, maxw = 1e7 + 100, inf = 2e9 + 100, sq = 300,
          mod = 1e9 + 9, LG = 17;
int n;
vector<int> e[maxn];
int a[maxn];
vector<int> ans;
bool vis[maxn];
void go(int v, int par) {
  ans.push_back(v);
  vis[v] = 1;
  for (int i : e[v])
    if (i != par && !vis[i]) go(i, v);
}
void dfs(int v, int par) {
  for (int i : e[v])
    if (i != par) {
      dfs(i, v);
      if (vis[i]) a[v] ^= 1;
    }
  if (a[v] == 0) go(v, par);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int v = i, u;
    cin >> u;
    u--;
    if (u >= 0) {
      e[v].push_back(u);
      e[u].push_back(v);
      a[v] ^= 1;
      a[u] ^= 1;
    }
  }
  dfs(0, -1);
  if (ans.size() < n)
    cout << "NO";
  else {
    cout << "YES\n";
    for (int i : ans) cout << i + 1 << '\n';
  }
}
