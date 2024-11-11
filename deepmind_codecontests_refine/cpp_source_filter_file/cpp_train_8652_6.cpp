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
vector<long long> fact;
void factcalc(long long n, long long M) {
  fact.resize(n + 1);
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fact[i] = mul(fact[i - 1], i, M);
  }
}
long long nCrM(long long n, long long r, long long M) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return mul(mul(fact[n], modInverse(fact[r], M), M),
             modInverse(fact[n - r], M), M);
}
long long rand_int(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  map<long long, long long> mm;
  for (auto& w : v) {
    cin >> w;
    mm[w]++;
  }
  vector<pair<long long, long long> > p;
  for (auto& w : mm) {
    p.push_back({w.second, w.first});
  }
  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  long long l = 1;
  long long r = 1e9;
  long long ans = 0;
  while (l < r) {
    long long m = (l + r + 1) / 2;
    long long f = 0;
    long long cnt = 0;
    for (long long i = 0; i < n; i++) {
      cnt += (p[i].first) / m;
      if (cnt >= k) {
        f = 1;
        break;
      }
    }
    if (f) {
      l = m;
      ans = m;
    } else {
      r = m - 1;
    }
  }
  long long c = 0;
  for (long long i = 0; i < n; i++) {
    long long op = p[i].first / ans;
    for (long long j = 0; j < op; j++) {
      cout << p[i].second << " ";
      c++;
      if (c >= k) {
        cout << '\n';
        return;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(20);
  solve();
  return 0;
}
