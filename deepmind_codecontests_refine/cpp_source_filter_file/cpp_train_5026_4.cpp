#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const long long linf = 4000000000000000000LL;
const int inf = 1000000007;
const long double pi = 3.1415926535;
long long maximum(long long x, long long y) {
  if (x > y) return x;
  return y;
}
long long minimum(long long x, long long y) {
  if (x < y) return x;
  return y;
}
void pv(vector<int> a) {
  for (auto& x : a) cout << x << " ";
  cout << '\n';
}
void pv(vector<long long> a) {
  for (auto& x : a) cout << x << " ";
  cout << '\n';
}
void pv(vector<vector<int> > a) {
  for (int i = (0); i < (a.size()); ++i) {
    cout << i << '\n';
    pv(a[i]);
    cout << '\n';
  }
}
void pv(vector<vector<long long> > a) {
  for (int i = (0); i < (a.size()); ++i) {
    cout << i << '\n';
    pv(a[i]);
  }
  cout << '\n';
}
void pv(vector<string> a) {
  for (auto& x : a) cout << x << '\n';
  cout << '\n';
}
int modInverse(int a, int m) {
  int m0 = m;
  int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    int q = a / m;
    int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long power(long long x, long long y) {
  long long k = 1 << 30;
  long long z = 1;
  while (k != 0) {
    z *= z;
    z %= inf;
    if (y >= k) {
      z *= x;
      z %= inf;
      y -= k;
    }
    k >>= 1;
  }
  return z;
}
long double area(pair<int, int> x, pair<int, int> y, pair<int, int> z) {
  return ((long long)x.second * y.first + (long long)y.second * z.first +
          (long long)z.second * x.first - (long long)x.first * y.second -
          (long long)y.first * z.second - (long long)z.first * x.second) /
         2.0;
}
bool clockwise(pair<int, int> x, pair<int, int> y, pair<int, int> z) {
  return area(x, y, z) > 0;
}
struct point {
  long double x, y;
};
long double area(point x, point y, point z) {
  return (x.y * y.x + y.y * z.x + z.y * x.x - x.x * y.y - y.x * z.y -
          z.x * x.y) /
         2.0;
}
bool clockwise(point x, point y, point z) { return area(x, y, z) > 0; }
int gcd(int a, int b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(a, b % a);
}
int popcount(int a) {
  int count = 0;
  while (a) {
    count += (a & 1);
    a >>= 1;
  }
  return count;
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
struct custom_hash_fast {
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    x ^= FIXED_RANDOM;
    return x ^ (x >> 16);
  }
};
long long choose(long long n, long long r) {
  long long p = 1, k = 1;
  if (n - r < r) r = n - r;
  if (r != 0) {
    while (r) {
      p *= n;
      k *= r;
      long long m = gcd(p, k);
      p /= m;
      k /= m;
      n--;
      r--;
    }
  } else
    p = 1;
  return p;
}
void setIO(string second) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
int main() {
  setIO("");
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int sign = !!(a + b);
    if (a == 0 && d == 0) {
      cout << (sign ? "Tidak Ya Tidak Tidak" : "Tidak Tidak Ya Tidak") << '\n';
    } else if (b == 0 && c == 0) {
      cout << (sign ? "Ya Tidak Tidak Tidak" : "Tidak Tidak Tidak Ya") << '\n';
    } else {
      cout << (sign ? "Ya Ya Tidak Tidak" : "Tidak Tidak Ya Ya") << '\n';
    }
  }
}
