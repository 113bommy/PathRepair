#include <bits/stdc++.h>
using namespace std;
const long long inf = (1ll << 62) - 1;
const long long mod = 1e9 + 7;
const long long N = 1e6 + 100;
const long double pi = 3.14159265358979323846;
const long double eps = 1e-7;
long long dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
long long dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
char dir[] = {'U', 'R', 'D', 'L'};
long long bPow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % mod;
    }
    b >>= 1;
    a = (a * a) % mod;
  }
  return res % mod;
}
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
vector<long long> fact(N, 0ll);
void factorial() {
  fact[0] = 1, fact[1] = 1;
  for (long long i = 2; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
}
long long ncr(long long n, long long r) {
  if (r > n) return 0;
  long long ans = fact[n] % mod;
  ans *= bPow(fact[r], mod - 2) % mod;
  ans %= mod;
  ans *= bPow(fact[n - r], mod - 2) % mod;
  ans %= mod;
  return ans;
}
vector<long long> primes(N, -1);
void sieve() {
  iota(primes.begin(), primes.end(), 0);
  for (long long i = 2; i < N; ++i) {
    if (primes[i] == i) {
      for (long long j = i * 2; j < N; j += i) {
        primes[j] = i;
      }
    }
  }
}
long long add(long long a, long long b) {
  a %= mod, b %= mod;
  return ((a + b) % mod + mod) % mod;
}
long long mul(long long a, long long b) {
  a %= mod, b %= mod;
  return ((a * b) % mod + mod) % mod;
}
long long sub(long long a, long long b) {
  a %= mod, b %= mod;
  return ((a - b + 2 * mod) % mod + mod) % mod;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n + 1);
  bool isPos = true;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
    if (i % 2 != a[i] % 2) {
      isPos = false;
    }
  }
  if (!isPos) {
    cout << -1 << "\n";
    return;
  }
  long long cur1 = n, r = n;
  vector<long long> ans;
  while (cur1 != 1) {
    long long cur2 = n - 1, pos = n;
    for (long long i = 1; i <= r; ++i) {
      if (a[i] == cur1) {
        pos = i;
        break;
      }
    }
    ans.push_back(pos);
    reverse(a.begin() + 1, a.begin() + pos + 1);
    for (long long i = 1; i <= r; ++i) {
      if (a[i] == cur2) {
        pos = i;
        break;
      }
    }
    ans.push_back(pos - 1);
    reverse(a.begin() + 1, a.begin() + pos);
    ans.push_back(pos + 1);
    reverse(a.begin() + 1, a.begin() + pos + 2);
    ans.push_back(3);
    reverse(a.begin() + 1, a.begin() + 4);
    ans.push_back(n);
    reverse(a.begin() + 1, a.begin() + n + 1);
    cur1 -= 2, r -= 2;
  }
  cout << ans.size() << "\n";
  for (long long x : ans) cout << x << " ";
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long tc = 1, test = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
