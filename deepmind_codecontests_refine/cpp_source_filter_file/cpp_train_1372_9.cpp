#include <bits/stdc++.h>
using namespace std;
const long long N = 200005;
vector<long long> vis(N);
vector<vector<long long>> adj(N);
void dfs(long long v) {
  vis[v] = 1;
  for (auto i : adj[v]) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  return;
}
bool isPrime(long long n) {
  if (n < 2) return false;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
long long factorial(long long n) {
  return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
long long power(long long x, long long y, long long mod) {
  long long res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res % mod;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
long long max(long long a, long long b) {
  long long ans = a > b ? a : b;
  return ans;
}
long long min(long long a, long long b) {
  long long ans = a < b ? a : b;
  return ans;
}
long long root(long long a[], long long i) {
  while (a[i] != i) {
    a[i] = a[a[i]];
    i = a[i];
  }
  return i;
}
void unionn(long long a[], long long i, long long j) {
  long long root_i = root(a, i);
  long long root_j = root(a, j);
  a[root_i] = root_j;
  return;
}
void fun() {}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  fun();
  long long tt = 1;
  while (tt--) {
    long long n;
    cin >> n;
    long long ar[n];
    for (long long i = 0; i < n; i++) cin >> ar[i];
    long long m;
    cin >> m;
    vector<long long> pos(n, -1), q;
    long long maxx = -1;
    for (long long i = 0; i < m; i++) {
      long long x;
      cin >> x;
      if (x == 1) {
        long long a, b;
        cin >> a >> b;
        ar[a - 1] = b;
        pos[a - 1] = i;
        q.push_back(0);
      } else {
        long long d;
        cin >> d;
        q.push_back(d);
        maxx = max(maxx, d);
      }
    }
    for (long long i = m - 2; i >= 0; i--) {
      q[i] = max(q[i], q[i + 1]);
    }
    for (long long i = 0; i < n; i++) {
      if (pos[i] == -1)
        ar[i] = max(maxx, ar[i]);
      else {
        ar[i] = max(ar[i], q[0]);
      }
    }
    for (long long i = 0; i < n; i++) cout << ar[i] << " ";
  }
  return 0;
}
