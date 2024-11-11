#include <bits/stdc++.h>
using namespace std;
struct fastio {
  char s[100000];
  int it, len;
  fastio() { it = len = 0; }
  inline char get() {
    if (it < len) return s[it++];
    it = 0;
    len = fread(s, 1, 100000, stdin);
    if (len == 0)
      return EOF;
    else
      return s[it++];
  }
  bool notend() {
    char c = get();
    while (c == ' ' || c == '\n') c = get();
    if (it > 0) it--;
    return c != EOF;
  }
} _buff;
inline long long getnum() {
  long long r = 0;
  bool ng = 0;
  char c;
  c = _buff.get();
  while (c != '-' && (c < '0' || c > '9')) c = _buff.get();
  if (c == '-') ng = 1, c = _buff.get();
  while (c >= '0' && c <= '9') r = r * 10 + c - '0', c = _buff.get();
  return ng ? -r : r;
}
template <class T>
inline void putnum(T x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
inline char getreal() {
  char c = _buff.get();
  while (c <= 32) c = _buff.get();
  return c;
}
const int mod = 1e9 + 7;
long long qpow(long long x, long long k) {
  return k == 0 ? 1
                : 1ll * qpow(1ll * x * x % mod, k >> 1) * (k & 1 ? x : 1) % mod;
}
int n;
int dp[100111][2];
vector<int> con[100111];
int ans = 1;
void dfs(int x, int pre = -1) {
  int sz = con[x].size() - (pre != -1);
  dp[x][0] = sz;
  dp[x][1] = 1;
  for (auto u : con[x]) {
    if (u == pre) continue;
    dfs(u, x);
    dp[x][0] = max(dp[x][0], dp[u][0] + sz - 1);
    dp[x][0] = max(dp[x][0], dp[u][0] + sz - 1);
    dp[x][1] = max(dp[x][1], dp[u][0] + 1);
  }
  ans = max(ans, dp[x][1]);
  ans = max(ans, dp[x][0] + (pre != -1));
  vector<int> v;
  for (auto u : con[x]) {
    if (u == pre) continue;
    v.push_back(max(dp[u][0] - 1, dp[u][1] - 1));
  }
  v.push_back(0);
  v.push_back(0);
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  ans = max(ans, v[0] + v[1] + int(con[x].size()));
  v.clear();
  for (auto u : con[x]) {
    if (u == pre) continue;
    v.push_back(dp[u][0]);
  }
  v.push_back(0);
  v.push_back(0);
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  ans = max(ans, v[0] + v[1] + 1);
}
int main() {
  n = getnum();
  for (int i = 1; i < n; i++) {
    int x, y;
    x = getnum(), y = getnum();
    con[x].push_back(y);
    con[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) ans = max(ans, (int)con[i].size());
  dfs(1);
  cout << ans << endl;
  return 0;
}
