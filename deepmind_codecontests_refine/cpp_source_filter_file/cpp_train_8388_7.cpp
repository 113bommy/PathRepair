#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 1e6 + 100;
const int eps = 1e-6;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
bool prime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long power(long long b, long long p) {
  if (p == 0) return 1;
  long long sq = power(b, p / 2);
  sq *= sq;
  if (p & 1) sq *= b;
  return sq;
}
long long ncr(long long n, long long r) {
  long long ans = 1;
  if (n - r < r) r = n - r;
  for (long long i = 0; i < r; i++) {
    ans *= n - i;
    ans /= i + 1;
  }
  return ans;
}
vector<long long> adj[MAX];
bool vis[MAX];
long long nodes, edges;
void dfs(int i) {
  vis[i] = 1, nodes++;
  for (auto j : adj[i]) {
    edges++;
    if (!vis[j]) dfs(j);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      edges = 0, nodes = 0;
      dfs(i);
      int c = nodes * (nodes - 1) / 2;
      edges /= 2;
      if (edges != c) return cout << "NO" << endl, 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
