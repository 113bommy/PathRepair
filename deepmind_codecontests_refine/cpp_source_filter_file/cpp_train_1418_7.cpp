#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-10;
const int inf = 2000000000;
const long long int MOD = 1000000007;
int MOD1 = 1000000007;
int MOD2 = 1000000009;
inline bool checkBit(long long int n, long long int i) {
  return n & (1LL << i);
}
inline long long int setBit(long long int n, long long int i) {
  return n | (1LL << i);
  ;
}
inline long long int resetBit(long long int n, long long int i) {
  return n & (~(1LL << i));
}
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline bool isLeapYear(long long int year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
inline void normal(long long int &a) {
  a %= MOD;
  (a < 0) && (a += MOD);
}
inline long long int modMul(long long int a, long long int b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a * b) % MOD;
}
inline long long int modAdd(long long int a, long long int b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a + b) % MOD;
}
inline long long int modSub(long long int a, long long int b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long int modPow(long long int b, long long int p) {
  long long int r = 1LL;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1LL;
  }
  return r;
}
inline long long int modDiv(long long int a, long long int b) {
  return modMul(a, modPow(b, MOD - 2));
}
bool comp(const pair<long long int, pair<long long int, long long int> > &p1,
          const pair<long long int, pair<long long int, long long int> > &p2) {
  return p1.first > p2.first;
}
long long int converter(string a) {
  long long int i, mul = 1, r, t, ans = 0LL;
  if (a.length() == 0) return 0;
  for (i = a.length() - 1; i >= 0; i--) {
    t = a[i] - '0';
    r = t % 10;
    ans += (mul * r);
    mul = mul * 10;
  }
  return ans;
}
long long int dp[200005][3][11];
vector<vector<long long int> > dp1;
vector<vector<long long int> > dp2;
vector<vector<long long int> > dp3;
long long int make, m, n, k, node, par[200005];
bool vis[200005];
vector<int> adj[200005];
vector<int> temp;
long long int solve1(int idx, int amount) {
  if (idx == temp.size()) {
    if (amount == 0)
      return 1;
    else
      return 0;
  }
  if (dp1[idx][amount] != -1) {
    return dp1[idx][amount];
  }
  long long int ret = 1LL, i, v = temp[idx], tot = 0LL;
  for (i = 0; i <= make; ++i) {
    if (amount - i < 0) break;
    long long int cur = (dp[v][0][i] + dp[v][1][i] + dp[v][2][i]) % MOD;
    tot += ((cur * solve1(idx + 1, amount - i)) % MOD);
    if (tot >= MOD) tot -= MOD;
  }
  return dp1[idx][amount] = tot;
}
long long int solve2(int idx, int amount) {
  if (idx == temp.size()) {
    if (amount == 0)
      return 1;
    else
      return 0;
  }
  if (dp2[idx][amount] != -1) return dp2[idx][amount];
  long long int ret = 1LL, i, v = temp[idx], tot = 0LL;
  for (i = 0; i <= make; ++i) {
    if (amount - i < 0) break;
    long long int cur = dp[v][0][i];
    tot += ((cur * solve2(idx + 1, amount - i)) % MOD);
    if (tot >= MOD) tot -= MOD;
  }
  return dp2[idx][amount] = tot;
}
long long int solve3(int idx, int amount) {
  if (idx == temp.size()) {
    if (amount == 0)
      return 1;
    else
      return 0;
  }
  if (dp3[idx][amount] != -1) return dp3[idx][amount];
  long long int ret = 1LL, i, v = temp[idx], tot = 0LL;
  for (i = 0; i <= make; ++i) {
    if (amount - i < 0) break;
    long long int cur = (dp[v][0][i] + dp[v][2][i]) % MOD;
    tot += ((cur * solve3(idx + 1, amount - i)) % MOD);
    if (tot >= MOD) tot -= MOD;
  }
  return dp3[idx][amount] = tot;
}
void dfs(int u) {
  int v, i, f = 0, j;
  vis[u] = true;
  for (auto it : adj[u]) {
    v = it;
    if (!vis[v]) {
      par[v] = u;
      f = 1;
      dfs(v);
    }
  }
  if (!f) {
    dp[u][0][0] = k - 1;
    dp[u][1][1] = 1;
    dp[u][2][0] = m - k;
  } else {
    node = u;
    temp.clear();
    for (auto it : adj[u]) {
      if (it != par[u]) temp.push_back(it);
    }
    dp1.assign(adj[u].size() + 2, vector<long long int>(make + 1, -1));
    dp2.assign(adj[u].size() + 2, vector<long long int>(make + 1, -1));
    dp3.assign(adj[u].size() + 2, vector<long long int>(make + 1, -1));
    for (j = 0; j <= make; ++j) {
      for (i = 0; i <= 2; ++i) {
        if (i == 0)
          dp[u][i][j] = modMul(k - 1, solve1(0, j));
        else if (i == 1)
          dp[u][i][j] = solve2(0, j);
        else if (i == 2)
          dp[u][i][j] = modMul(m - k, solve3(0, j));
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int i, n, x, y, ans = 0LL, j;
  cin >> n >> m;
  for (i = 1; i <= n - 1; ++i) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  cin >> k >> make;
  dfs(1);
  for (i = 0; i <= 2; ++i) {
    for (j = 0; j <= make; ++j) {
      ans += dp[1][i][j];
      if (ans >= MOD) ans -= MOD;
    }
  }
  cout << ans << '\n';
  return 0;
}
