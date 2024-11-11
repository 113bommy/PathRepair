#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
const int mod = (int)1e9 + 7;
const long long INF64 = 3e18;
void smxl(long long &a, long long b) {
  if (a < b) a = b;
}
void smnl(long long &a, long long b) {
  if (a > b) a = b;
}
void adsl(long long &a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
}
void misl(long long &a, long long b) {
  a -= b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}
void smx(long long &a, long long b) {
  if (a < b) a = b;
}
void smn(long long &a, long long b) {
  if (a > b) a = b;
}
void ads(long long &a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
}
void mis(long long &a, long long b) {
  a -= b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long egcd(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = egcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
long long mbinp(long long a, long long b) {
  a %= mod;
  if (b == 0) return 1;
  long long ans = mbinp(a, b / 2);
  long long tmp = (ans * ans) % mod;
  if (b % 2) return ((tmp * a) % mod);
  return ((tmp) % mod);
}
long long binp(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = binp(a, b / 2);
  long long tmp = (ans * ans);
  if (b % 2) return ((tmp * a));
  return ((tmp));
}
long long C(int n, int m) {
  long long ret = 1;
  for (int i = 1; i <= m; i++) {
    ret *= (n - i + 1);
    ret /= i;
  }
  return ret;
}
long long overbinp(long long a, int b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      if (res < INF64 / a)
        res *= a;
      else
        return INF64;
    }
    if (b > 1) {
      if (a < INF64 / a)
        a *= a;
      else
        return INF64;
    }
    b >>= 1;
  }
  return res;
}
int reach[21];
int used[21];
vector<int> adj[1000010];
vector<int> radj[1000010];
void dfs(int n) {
  used[n] = 1;
  for (int z : adj[n])
    if (used[z] == 0) dfs(z);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> sinks;
  vector<int> srcs;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    radj[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    if (radj[i].size() == 0) srcs.push_back(i);
    if (adj[i].size() == 0) sinks.push_back(i);
  }
  for (int i = 0; i < srcs.size(); i++) {
    memset(used, 0, sizeof(used));
    dfs(srcs[i]);
    for (int j = 0; j < sinks.size(); j++)
      if (used[sinks[j]] == 1) reach[srcs[i]] ^= (1 << j);
  }
  int cnt = srcs.size();
  bool ok = true;
  for (int msk = 0; msk < (1 << cnt); msk++) {
    int res = 0;
    for (int i = 0; i < cnt; i++)
      if (msk & (1 << i)) res |= reach[srcs[i]];
    int s1 = __builtin_popcount(msk);
    int s2 = __builtin_popcount(res);
    if (s2 < s1 || s2 == s1 && s1 != 0 && s1 != cnt) ok = false;
  }
  cout << (ok ? "YES" : "NO");
}
