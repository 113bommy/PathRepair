#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979323;
long long mod = 1000000000 + 7;
long long modu = 998244353;
const long double pii = acos(-1.0);
const long long INF = 1e18;
const long long inf = 1e9;
long long power(long long x, long long y) {
  long long res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long powe(long long x, long long y) {
  x = x % mod, y = y % (mod - 1);
  long long ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans = (1ll * x * ans) % mod;
    }
    y >>= 1;
    x = (1ll * x * x) % mod;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
bool isPrime(long long n) {
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
long long ncr(long long n, long long r) {
  long long res = 1;
  if (r > n) return 0;
  if (r > n - r) r = n - r;
  for (long long i = 0; i < r; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
void fun() {}
const long long N = 407;
void pre() {}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  fun();
  pre();
  long long tttt = 1;
  while (tttt--) {
    long long n, size;
    cin >> n >> size;
    size *= 8;
    long long a[n];
    map<long long, long long> m;
    set<long long> s;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
      s.insert(a[i]);
    }
    long long ele = (long long)(m.size());
    long long b[ele];
    for (long long i = 0; i < ele; i++) {
      b[i] = *s.begin();
      s.erase(s.begin());
    }
    if (ceil(log2((long long)(m.size()))) * n <= size) {
      cout << 0 << "\n";
      return 0;
    }
    sort(b, b + ele);
    long long ans = 0;
    long long i, j;
    std::vector<long long> temp;
    for (auto i : m) {
      temp.push_back(i.second);
    }
    std::vector<long long> h(ele + 1);
    for (long long i = 1; i <= ele; i++) {
      h[i] = temp[i - 1];
    }
    for (long long i = 1; i <= ele; i++) h[i] += h[i - 1];
    long long ye = size / n;
    ye = pow(2, ye);
    ans = inf;
    for (long long i = ye; i <= ele; i++) {
      ans = min(ans, n - (h[i] - h[i - ye + 1]));
    }
    cout << ans;
  }
  return 0;
}
