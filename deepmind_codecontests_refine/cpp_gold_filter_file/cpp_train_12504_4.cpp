#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e9 + 1;
const double pi = 3.1415926535897932384626433832;
const long long M = 2e18 + 7;
long long bis(long long a[], long long l, long long r, long long x) {
  while (l <= r) {
    long long m = l + (r - l) / 2;
    if (a[m] == x) return m;
    if (a[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}
void addEdge(vector<long long> adj[], long long u, long long v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
void DFSUtil(long long u, vector<long long> adj[], vector<bool> &visited) {
  visited[u] = true;
  for (long long i = 0; i < adj[u].size(); i++)
    if (visited[adj[u][i]] == false) DFSUtil(adj[u][i], adj, visited);
}
void DFS(vector<long long> adj[], long long V) {
  vector<bool> visited(V, false);
  for (long long u = 0; u < V; u++)
    if (visited[u] == false) DFSUtil(u, adj, visited);
}
void addEdge(vector<pair<long long, long long> > adj[], long long u,
             long long v, long long wt) {
  adj[u].push_back(make_pair(v, wt));
  adj[v].push_back(make_pair(u, wt));
}
long long gcd(long long x, long long y) {
  if (x == 0)
    return y;
  else
    return gcd(y % x, x);
}
long long lcm(long long x, long long y) { return (x * y) / gcd(x, y); }
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
bool pdrome(string s) {
  long long n = s.length();
  for (long long i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1]) {
      return false;
    }
  }
  return true;
}
long long mindig(long long x) {
  long long ans = 9;
  long long t = x;
  while (x) {
    ans = min(ans, x % 10);
    x /= 10;
  }
  x = t;
  return ans;
}
long long maxdig(long long x) {
  long long ans = 0;
  long long t = x;
  while (x) {
    ans = max(ans, x % 10);
    x /= 10;
  }
  x = t;
  return ans;
}
long long modpow(long long x, long long n, long long M) {
  if (n == 0) return 1 % M;
  long long u = modpow(x, n / 2, M);
  u = (u * u) % M;
  if (n % 2 == 1) u = (u * x) % M;
  return u;
}
long long sum(long long a) {
  long long result = 0;
  while (a > 0) {
    result += a % 10;
    a /= 10;
  }
  return result;
}
long long digits(long long n) { return floor(log10(n) + 1); }
vector<long long> v(200005);
long long maxm, minm;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long c = 0, sum = 0, ans = 0;
  for (long long j = a[n - 1]; j >= a[0]; j--) {
    while (j < a[n - 1 - c]) {
      c++;
    }
    sum += c;
    if (sum > k) {
      ans++;
      sum = c;
    }
  }
  if (sum) ans++;
  cout << ans;
  return 0;
}
