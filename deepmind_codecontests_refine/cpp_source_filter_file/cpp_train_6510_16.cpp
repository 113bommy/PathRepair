#include <bits/stdc++.h>
using namespace std;
long long i, j, k, x_gcd = 0, y_gcd, Gcd = 0;
vector<bool> prime(1000001, true);
list<pair<long long, long long> >::iterator i_lp;
list<long long>::iterator i_ls;
vector<long long>::iterator i_v;
vector<long long> spf(1000001);
string binary;
string conv_bin(long long n) {
  if (n / 2 != 0) {
    conv_bin(n / 2);
  }
  return binary += char(48 + n % 2);
}
inline int digsum(long long n) {
  int sum = 0;
  n = abs(n);
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
inline void fastsc(long long &x) {
  register long long c = getchar();
  x = 0;
  bool neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x * 10) + (c - 48);
  }
  if (neg) x = -x;
}
inline bool ispalin(string s) {
  for (int i = 0, j = s.size() - 1; i <= j; i++, j--)
    if (s[i] != s[j]) return false;
  return true;
}
bool ispow2(long long x) { return x && (!(x & (x - 1))); }
void inline extend_gcd(long long a, long long b) {
  if (b == 0) {
    Gcd = a;
    x_gcd = 1;
    y_gcd = 0;
  } else {
    extend_gcd(b, a % b);
    long long temp = x_gcd;
    x_gcd = y_gcd;
    y_gcd = temp - (a / b) * y_gcd;
  }
}
inline long long b_Search(vector<long long> arr, long long l, long long r,
                          long long x) {
  if (r >= l) {
    long long mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return b_Search(arr, l, mid - 1, x);
    return b_Search(arr, mid + 1, r, x);
  }
  return -1;
}
inline long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
inline long long is_prime(long long n) {
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
inline void Sieve_p(long long n) {
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * 2; i <= n; i += p) prime[i] = false;
    }
  }
}
inline void sieve_f() {
  spf[1] = 1;
  for (long long i = 2; i < 1000001; i++) spf[i] = i;
  for (long long i = 4; i < 1000001; i += 2) spf[i] = 2;
  for (long long i = 3; i * i < 1000001; i++) {
    if (spf[i] == i) {
      for (long long j = i * i; j < 1000001; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
inline long long pwr(long long x, long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = pwr(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
inline int pwr_mod(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
inline long long s_int(string a) {
  long long p = 0;
  for (i = 0; i < a.size(); i++) {
    p += (a[i] - 48);
    if (i != a.size() - 1) p = p * 10;
  }
  return p;
}
long long mod_inv_p(long long n, long long m) { return pwr_mod(n, m - 2, m); }
long long mod_inv(long long A, long long M) {
  extend_gcd(A, M);
  return (x_gcd % M + M) % M;
}
int main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (i = 0; i < n; i++) cin >> a[i];
  vector<pair<long long, long long> > v;
  long long m;
  cin >> m;
  long long u;
  for (i = 0; i < m; i++) {
    cin >> u;
    v.push_back(make_pair(u, 0));
  }
  for (i = 0; i < m; i++) {
    cin >> u;
    v[i].second = u;
  }
  sort(a.begin(), a.end());
  ;
  long long ans = 0;
  long long x = -1;
  long long vv = 0;
  for (i = 0; i < m; i++) {
    std::vector<long long>::iterator low, up;
    low = std::lower_bound(a.begin(), a.end(), v[i].first);
    up = std::upper_bound(a.begin(), a.end(), v[i].first);
    long long l = low - a.begin();
    long long r = up - a.begin();
    low = std::lower_bound(a.begin(), a.end(), v[i].second);
    up = std::upper_bound(a.begin(), a.end(), v[i].second);
    long long c = low - a.begin();
    long long z = up - a.begin();
    if (ans < (r - l)) {
      ans = (r - l);
      x = i;
      vv = (z - c);
    } else if (ans == (r - l)) {
      if (vv < (z - c)) {
        ans = (r - l);
        vv = (z - c);
        x = i;
      }
    }
  }
  cout << x + 1 << endl;
  return 0;
}
