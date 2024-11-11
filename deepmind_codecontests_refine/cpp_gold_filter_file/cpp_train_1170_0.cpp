#include <bits/stdc++.h>
const double PI = 3.141592653589793238463;
using namespace std;
inline long long add(long long a, long long b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
  return a;
}
inline long long sub(long long a, long long b) {
  a -= b;
  if (a < 0) a += 1000000007;
  return a;
}
inline long long mul(long long a, long long b) {
  return (long long)((long long)a * b % 1000000007);
}
long long fast_power(long long base, long long power) {
  long long result = 1;
  while (power > 0) {
    if (power % 2 == 1) {
      result = (result * base);
    }
    base = (base * base);
    power = power / 2;
  }
  return result;
}
long long min(long long a, long long b) { return a > b ? b : a; }
long long max(long long a, long long b) { return a > b ? a : b; }
void SieveOfEratosthenes(long long n, unordered_set<long long> &s) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long p = 2; p <= n; p++)
    if (prime[p]) s.insert(p);
}
void dfs(long long s, vector<bool> &vis, vector<vector<long long>> &adlist) {
  if (vis[s]) return;
  vis[s] = true;
  for (auto x : adlist[s]) {
    if (vis[x] == false) {
      cout << s << " " << x << "\n";
    }
    dfs(x, vis, adlist);
  }
}
void bfs(long long x, vector<bool> &vis, vector<vector<long long>> &adlist) {
  queue<long long> q;
  vis[x] = true;
  q.push(x);
  while (!q.empty()) {
    long long s = q.front();
    q.pop();
    for (auto u : adlist[s]) {
      if (vis[u]) continue;
      vis[u] = true;
      q.push(u);
    }
  }
}
bool bpchk(vector<vector<long long>> &adj, vector<long long> &color) {
  color[1] = 1;
  queue<long long> q;
  q.push(1);
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    for (auto x : adj[u]) {
      if (color[x] == -1) {
        color[x] = color[u] ^ 1;
        q.push(x);
      }
    }
  }
  for (long long i = 1; i < adj.size(); i++) {
    for (auto x : adj[i]) {
      if (color[x] == color[i]) return false;
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n, m, x, y;
    cin >> n >> m >> x >> y;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (long long j = 0; j < m; j++) {
        if (s[j] == '.') {
          long long t = 0;
          while (s[j] == '.' && j < m) {
            t += 1;
            j += 1;
          }
          if (2 * x <= y) {
            ans += t * x;
          } else {
            ans += (t / 2) * y + (t % 2) * x;
          }
        }
      }
    }
    cout << ans << "\n";
  }
}
