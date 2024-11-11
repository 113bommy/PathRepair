#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("avx")
const long long INF = numeric_limits<long long>::max();
const long double PI = 3.1415926535898;
const long long MOD = 1000000007;
const long long LIM = 100005;
long long fpow(long long x, long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = fpow(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void sieve(long long n) {
  bool prime[5 * LIM];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++)
    if (prime[p] == true)
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
  prime[1] = 0;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
map<long long, long long> primeFactors(long long n) {
  map<long long, long long> mp;
  while (n % 2 == 0) {
    if (mp.count(2) == 1)
      mp[2]++;
    else
      mp.insert({2, 1});
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      if (mp.count(i) == 1)
        mp[i]++;
      else
        mp.insert({i, 1});
      n = n / i;
    }
  }
  if (n > 2) {
    if (mp.count(n) == 1)
      mp[n]++;
    else
      mp.insert({n, 1});
  }
  return mp;
}
vector<long long> adj[105];
bool visited[105];
long long marked[105];
void dfs(long long u, long long val) {
  visited[u] = true;
  marked[u] = val;
  if (val == 1)
    val = 2;
  else
    val = 1;
  for (auto x : adj[u]) {
    if (!visited[x]) dfs(x, val);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long n = s.length();
  cout << 3 << "\n";
  cout << "L " << 2 << "\n";
  cout << "R " << 2 << "\n";
  cout << "R " << 2 * n - 1 << "\n";
  return 0;
}
