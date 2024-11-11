#include <bits/stdc++.h>
using namespace std;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
const long double pi = 3.14159265359;
const long long mod = 1000000007;
const long long modc = 998244353;
const long long inf = LLONG_MAX;
const long long neg_inf = LLONG_MIN;
long long inline power(long long a, long long b, long long p) {
  a %= p;
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return ans;
}
long long mod_inv(long long n, long long p) { return power(n, p - 2, p); }
bool inline isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
template <typename... T>
void W(T &&...args) {
  ((cout << fixed << setprecision(17) << args << " "), ...);
  cout << endl;
}
template <typename... T>
void R(T &&...args) {
  ((cin >> args), ...);
}
long long ston(string s) {
  long long a = 0;
  reverse(s.begin(), s.end());
  long long pow = 1;
  for (long long i = 0; i < s.size(); i++) {
    a += pow * (s[i] - '0');
    pow *= 10;
  }
  return a;
}
template <class T>
string to_binary(T n) {
  string binaryNum;
  long long i = 0;
  while (n > 0) {
    binaryNum.push_back((n % 2) + '0');
    n = n / 2;
    i++;
  }
  if ((long long)binaryNum.size() == 0) binaryNum.push_back('0');
  reverse(binaryNum.begin(), binaryNum.end());
  return binaryNum;
}
long long bton(string &s, long long base) {
  long long ans = 0;
  long long pow = 1;
  reverse(s.begin(), s.end());
  for (auto x : s) {
    if (x >= 'a' && x <= 'z')
      ans += (x - 'a' + 10) * pow;
    else
      ans += (x - '0') * pow;
    pow *= base;
  }
  return ans;
}
template <class T>
void wv(T &v) {
  for (auto x : v) cout << x << " ";
  cout << endl;
}
template <class T>
void rv(T &v) {
  for (long long i = 0; i < (long long)v.size(); i++) cin >> v[i];
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
const long long M = 2e5;
void solve() {
  long long i, j, sum = 0, prod = 1, maxl = neg_inf, minl = inf;
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  rv(a);
  vector<long long> b;
  b.push_back(a.front());
  for (i = 1; i < n; i++)
    if (a[i] != a[i - 1]) b.push_back(a[i]);
  n = (long long)b.size();
  vector<long long> val(k + 1);
  for (i = 0; i < n; i++) {
    if (i == 0 || i == n - 1) {
      val[b[i]]++;
      continue;
    }
    if (b[i - 1] == b[i + 1])
      val[b[i]] += 2;
    else
      val[b[i]]++;
  }
  long long ans = 0;
  for (i = 1; i <= k; i++)
    if (val[i] > maxl) {
      maxl = val[i];
      ans = i;
    }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  while (t--) {
    solve();
  }
}
