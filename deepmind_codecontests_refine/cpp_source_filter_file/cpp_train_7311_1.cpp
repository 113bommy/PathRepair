#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const int MOD = 1000000007;
const int INF = 1000000009;
const int MAXN = 1000005;
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
template <typename T, typename... Args>
inline string arrStr(T arr, int n) {
  stringstream s;
  s << "[";
  for (int i = 0; i < n - 1; i++) s << arr[i] << ",";
  s << arr[n - 1] << "]";
  return s.str();
}
bool check_prime(long long n) {
  if (n < 2) return false;
  for (long long x = 2; x * x <= n; x++) {
    if (n % x == 0) return false;
  }
  return true;
}
vector<long long> get_prime_factors(long long n) {
  vector<long long> f;
  for (long long x = 2; x * x <= n; x++) {
    while (n % x == 0) {
      f.push_back(x);
      n /= x;
    }
  }
  if (n > 1) f.push_back(n);
  return f;
}
long long fpow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res = (1LL * res * x) % MOD;
    }
    x = (1LL * x * x) % MOD;
    n >>= 1;
  }
  return (res % MOD);
}
vector<long long> fac, inv;
void create_fac(long long n = MAXN) {
  fac.resize(n + 5);
  inv.resize(n + 5);
  fac[0] = 1;
  inv[0] = fpow(fac[0], MOD - 2);
  for (long long i = 1; i <= n; i++) {
    fac[i] = (fac[i - 1] % MOD * i % MOD) % MOD;
    inv[i] = fpow(fac[i], MOD - 2);
  }
}
long long binomial_coefficient(long long n, long long r) {
  long long res = 1;
  res = (res * (fac[n] % MOD)) % MOD;
  res = (res * (inv[r] % MOD)) % MOD;
  res = (res * (inv[n - r] % MOD)) % MOD;
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
long long sceil(long long a, long long b) { return (a + b - 1) / b; }
vector<long long> lp;
vector<long long> pr;
void sieve(long long n = MAXN) {
  lp.resize(n + 1);
  lp.clear();
  for (long long i = 2; i <= n; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (long long j = 0;
         j < (long long)pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; ++j)
      lp[i * pr[j]] = pr[j];
  }
}
int extended_euclidean(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
int mod_inv(int a, int m) {
  int x, y;
  int g = extended_euclidean(a, m, x, y);
  if (g != 1) {
    return -1;
  } else {
    x = (x % m + m) % m;
    return x;
  }
}
long long solution() {
  long long n = 0;
  cin >> n;
  vector<long long> a(n, 0), b(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    b[i + 1] = a[i] + b[i];
  }
  set<int> s;
  s.insert(b[0]);
  long long ans = 0, rv = 1;
  for (int i = 1; i < n + 1; i++) {
    while (rv < n + 1) {
      if (s.find(b[rv]) != s.end()) {
        s.erase(b[i - 1]);
        break;
      }
      s.insert(b[rv]);
      rv++;
    }
    ans += rv - i;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tt = 1;
  while (tt--) {
    cout << solution() << '\n';
  }
  return 0;
}
