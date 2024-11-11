#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long maxn = 1e5 + 1;
void swap(long long *xp, long long *yp) {
  long long temp = *xp;
  *xp = *yp;
  *yp = temp;
}
void print(vector<long long> v) {
  long long i, j, n = v.size();
  for (i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}
void scan(vector<long long> &v, long long n) {
  for (long long i = 0; i < n; i++) cin >> v[i];
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y / 2;
    x = (x * x) % mod;
  }
  return res % mod;
}
long long modinv(long long x) { return power(x, mod - 2) % mod; }
vector<bool> prime(maxn, true);
void sieve() {
  long long n = maxn;
  prime[0] = false;
  prime[1] = false;
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
int main() {
  long long int i, j, inc, dec, t, r;
  long long int c, d, e, temp, m, p, w, k, x, y, sum, pre, temp2, mid, n, low,
      high, ans;
  t = 1;
  n = 1;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<long long> adj[n + 1];
    for (i = 0; i < n - 1; i++) {
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    if (adj[k].size() == 1) {
      cout << "Ayush"
           << "\n";
      continue;
    }
    if (n % 2 == 0) {
      cout << "Ayush"
           << "\n";
      continue;
    }
    cout << "Ashish"
         << "\n";
  }
  return 0;
}
