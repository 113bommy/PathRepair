#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const long long LL_INF = 1ll * INF * INF;
const int MAX_N = 1000000 + 7;
template <typename T>
inline void addmod(T& a, const long long& b, const int& MOD = INF) {
  a = (a + b) % MOD;
  if (a < 0) a += MOD;
}
const int mod = INF;
long long f[MAX_N];
int n;
vector<int> adj[MAX_N];
int rev[MAX_N];
long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); }
vector<int> divisors[MAX_N];
void init() {
  for (int i = 1; i < MAX_N; ++i)
    if (!rev[i]) {
      for (int j = i; j < MAX_N; j += i)
        if (rev[j]) divisors[j].push_back(i);
    }
}
void dfs(int u) {
  for (int v : adj[u]) {
    dfs(v);
    f[u] += f[v];
  }
}
bool check(int d) {
  if (d == 1) return true;
  if (f[0] % d) return false;
  int cnt = 0;
  for (int c : divisors[d]) {
    cnt += rev[c];
  }
  return d == cnt;
}
int ans[MAX_N];
void solve() {
  cin >> n;
  for (int i = (0), _b = (n); i < _b; ++i) cin >> f[i];
  for (int i = (1), _b = (n); i < _b; ++i) {
    int p;
    cin >> p;
    adj[p - 1].push_back(i);
  }
  dfs(0);
  for (int i = 0; i < n; ++i) {
    long long d = gcd(f[i], f[0]);
    if (f[0] / d < MAX_N) {
      rev[f[0] / d]++;
    }
  }
  init();
  for (int i = n; i > 0; --i)
    if (check(i)) {
      ans[i] += 1;
      if (ans[i] >= mod) ans[i] -= mod;
      for (int c : divisors[i])
        if (c != i) {
          ans[c] += ans[i];
          if (ans[c] >= mod) ans[c] -= mod;
        }
    }
  cout << ans[1] << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  const bool multiple_test = false;
  int test = 1;
  if (multiple_test) cin >> test;
  for (int i = 0; i < test; ++i) {
    solve();
  }
}
