#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 50;
const long long mod = 1e9 + 7;
const long long INF = 1e18;
long long dx[] = {-1, 0, 1, 0};
long long dy[] = {0, 1, 0, -1};
bool compare(const pair<long long, long long> &i,
             const pair<long long, long long> &j) {
  return i.second < j.second;
}
long long modexp(long long x, long long n) {
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return r % mod;
}
long long modinv(long long x) { return modexp(x, mod - 2); }
vector<long long> sieve(long long n) {
  long long *arr = new long long[n + 1]();
  vector<long long> vect;
  for (long long i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (long long j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long mod_sub(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a - b) % mod) + mod) % mod;
}
long long mod_div(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (mod_mul(a, modinv(b)) + mod) % mod;
}
void _print(long long x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(string x) { cerr << x; }
void _print(bool x) { cerr << x; }
void _print(long double x) { cerr << x; }
template <class T>
void _print(vector<T> A) {
  cerr << "[ ";
  for (T x : A) {
    _print(x);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> A) {
  cerr << "[ ";
  for (T x : A) {
    _print(x);
    cerr << " ";
  }
  cerr << "]";
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> A(n);
  for (auto &x : A) cin >> x;
  if (n % 2 == 0) {
    cout << 0 << "\n";
    return;
  }
  long long mn = INT_MAX;
  for (long long i = 0; i < n; i += 2) {
    mn = min(mn, A[i]);
  }
  if (n == 1) {
    if (m * k <= n)
      cout << m * k << "\n";
    else
      cout << n << "\n";
    return;
  }
  long long x = (n - 1) / 2 + 1;
  long long times = m / x;
  if (m < x) {
    cout << 0 << "\n";
    return;
  } else {
    if (times * k <= mn)
      cout << times * k << "\n";
    else
      cout << mn << "\n";
  }
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
