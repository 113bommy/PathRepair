#include <bits/stdc++.h>
using namespace std;
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
long long power(long long a, long long b) {
  long long result = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      result *= a;
    }
    a *= a;
    b /= 2;
  }
  return result;
}
long long gcd(long long x, long long y) {
  long long r;
  while (y != 0 && (r = x % y) != 0) {
    x = y;
    y = r;
  }
  return y == 0 ? x : y;
}
long long countSetBits(long long x) {
  long long Count = 0;
  while (x > 0) {
    if (x & 1) Count++;
    x = x >> 1;
  }
  return Count;
}
bool isPerfectSquare(long long n) {
  long long sr = sqrt(n);
  if (sr * sr == n)
    return true;
  else
    return false;
}
long long mod(long long x, long long M) { return ((x % M + M) % M); }
long long add(long long a, long long b, long long M) {
  return mod(mod(a, M) + mod(b, M), M);
}
long long mul(long long a, long long b, long long M) {
  return mod(mod(a, M) * mod(b, M), M);
}
long long powerM(long long a, long long b, long long M) {
  long long res = 1ll;
  while (b) {
    if (b % 2ll == 1ll) {
      res = mul(a, res, M);
    }
    a = mul(a, a, M);
    b /= 2ll;
  }
  return res;
}
long long mod_inv(long long a, long long m) {
  long long g = m, r = a, x = 0, y = 1;
  while (r != 0) {
    long long q = g / r;
    g %= r;
    swap(g, r);
    x -= q * y;
    swap(x, y);
  }
  return mod(x, m);
}
long long nCr(long long n, long long k) {
  if (n < k) return 0;
  if (k == 0) return 1;
  long long res = 1;
  if (k > n - k) k = n - k;
  for (long long i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
long long modInverse(long long n, long long M) { return powerM(n, M - 2, M); }
vector<long long> factu;
void factcalc(long long n, long long M) {
  factu.resize(n + 1);
  factu[0] = 1;
  for (long long i = 1; i <= n; i++) {
    factu[i] = mul(factu[i - 1], i, M);
  }
}
long long nCrM(long long n, long long r, long long M) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return mul(mul(factu[n], modInverse(factu[r], M), M),
             modInverse(factu[n - r], M), M);
}
long long rand_int(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
void solve() {
  vector<long long> v(19);
  v[1] = 9;
  v[2] = 9;
  for (long long i = 3; i <= 18; i++) {
    v[i] = 9 * (power(10, i - 2));
  }
  long long l, r;
  cin >> l >> r;
  if (l == power(1, 18)) l--;
  if (r == power(1, 18)) r--;
  string a, b;
  a = to_string(l);
  b = to_string(r);
  long long lcnt = 0, rcnt = 0;
  if (a.size() == 1) {
    lcnt = 10 - l;
  }
  if (b.size() == 1) {
    rcnt = 10 - r;
  }
  if (a.size() == 2) {
    for (long long i = l; i <= 99; i++) {
      if (i % 10 == i / 10) {
        lcnt++;
      }
    }
  }
  if (b.size() == 2) {
    for (long long i = r; i <= 99; i++) {
      if (i % 10 == i / 10) {
        rcnt++;
      }
    }
  }
  string a3;
  if (a.size() > 2) a3 = a.substr(1, a.size() - 2);
  string b3;
  if (b.size() > 2) b3 = b.substr(1, b.size() - 2);
  string buff_a = "", buff_b = "";
  for (long long i = 0; i < a3.size(); i++) {
    buff_a += "9";
  }
  for (long long i = 0; i < b3.size(); i++) {
    buff_b += "9";
  }
  long long bu_a = 0;
  if (buff_a.size() > 0) bu_a = stoll(buff_a);
  long long bu_b = 0;
  if (buff_b.size() > 0) bu_b = stoll(buff_b);
  long long num_a = 0;
  if (a3.size() > 0) num_a = stoll(a3);
  long long num_b = 0;
  if (b3.size() > 0) num_b = stoll(b3);
  long long l1 = bu_a - num_a + 1;
  long long r1 = bu_b - num_b + 1;
  if (a[0] < a.back()) {
    l1--;
  }
  if (b[0] < b.back()) {
    r1--;
  }
  long long ll1 = '9' - a[0];
  for (long long i = 1; i < a.size() - 1; i++) {
    ll1 *= 10;
  }
  long long rr1 = '9' - b[0];
  for (long long i = 1; i < b.size() - 1; i++) {
    rr1 *= 10;
  }
  l1 += ll1;
  r1 += rr1;
  if (a.size() <= 2) {
    l1 = lcnt;
  }
  if (b.size() <= 2) {
    r1 = rcnt;
  }
  if (a.size() == b.size()) {
    long long ans = l1 - r1;
    if (b[0] == b.back()) {
      ans++;
    }
    cout << ans << '\n';
    return;
  }
  long long ans = l1;
  for (long long i = a.size() + 1; i <= b.size(); i++) {
    ans += v[i];
  }
  ans -= r1;
  if (b[0] == b.back()) {
    ans++;
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(20);
  solve();
  return 0;
}
