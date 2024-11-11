#include <bits/stdc++.h>
long long shouldendl = 1;
long long INF = (long long)(1e16 + 7);
long long MOD = (long long)(1e9 + 7);
using namespace std;
long long modInverse(long long a) {
  long long m = MOD, m0 = m, y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m, t = m;
    m = a % m, a = t, t = y;
    y = x - q * y, x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long add(long long a, long long b) {
  return ((a % MOD) + (b % MOD)) % MOD;
}
long long mul(long long a, long long b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}
long long sub(long long a, long long b) {
  long long ans = ((a % MOD - b % MOD)) % MOD;
  if (ans < 0) ans += MOD;
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long get(long long f = 2) {
  if (f != 2) return 1;
  long long t;
  cin >> t;
  ;
  return t;
}
template <class T>
long long logd(T name) {
  cout << name << endl;
  return 0;
}
long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long res = 1;
  x = x % MOD;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % MOD;
    y = y >> 1;
    x = (x * x) % MOD;
  }
  return res;
}
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U> &l, const std::pair<T, U> &r) {
  return {l.first + r.first, l.second + r.second};
}
long long popcnt(long long x) { return __builtin_popcountll(x); }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
template <class T>
bool input(vector<T> &v, long long n = -1) {
  if (n == -1) assert(v.size() != 0);
  if (n == -1) n = v.size();
  for (auto &i : v) cin >> i;
  return 0;
}
template <class T>
bool print(vector<T> v, long long l = 0, long long r = -1) {
  if (r == -1) r = v.size();
  for (long long i = l; i < r; i++) cout << v[i] << " ";
  return 0;
}
void MAIN(long long i, long long t);
void test(long long t) {
  for (long long i = 1; i <= t; i++) {
    MAIN(i, t);
    if (shouldendl) cout << "\n";
  }
}
void MAIN(long long current_test_case, long long total_test_cases) {
  long long n, m;
  cin >> n >> m;
  vector<long long> v(n);
  input(v);
  vector<long long> inc(n, 1), dec(n, 1), dec1(n, 1);
  for (long long i = 1; i < n; i++) {
    if (v[i - 1] <= v[i]) inc[i] += inc[i - 1];
  }
  for (long long i = 1; i < n; i++)
    if (v[i - 1] >= v[i]) dec[i] += dec[i - 1];
  for (long long i = n - 2; i >= 0; i--)
    if (v[i] >= v[i + 1]) {
      dec1[i] += dec[i - 1];
    }
  for (long long i = 0; i < m; i++) {
    long long l, r;
    cin >> l >> r;
    l--;
    r--;
    long long mid = r - dec[r] + 1;
    long long sum =
        min(mid - l + 1, inc[mid]) + min(dec1[mid], r - mid + 1) - 1;
    if (sum >= (r - l + 1)) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    cout << endl;
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  shouldendl = 1;
  test(get(1));
  return 0;
}
