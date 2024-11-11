#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
long long mod = 1000000007;
long long mod2 = 1000000009;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
bool is_vowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
  return 0;
}
double getDistance(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
long long extended_euclidean(long long a, long long b, long long &x,
                             long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long g = extended_euclidean(b, a % b, y, x);
  y -= (a / b) * x;
  return g;
}
long long power(long long base, long long p) {
  if (p == 1) return base;
  if (!p) return 1ll;
  long long ret = power(base, p / 2);
  ret *= ret;
  ret %= mod;
  if (p & 1) ret *= base;
  return ret % mod;
}
pair<long long, long long> vec(pair<long long, long long> a,
                               pair<long long, long long> b) {
  pair<long long, long long> ret =
      pair<long long, long long>(a.first - b.first, a.second - b.second);
  return ret;
}
long long getArea(pair<long long, long long> a, pair<long long, long long> b,
                  pair<long long, long long> c) {
  pair<long long, long long> x = vec(a, b);
  pair<long long, long long> y = vec(c, b);
  return abs(x.first * y.second - x.second * y.first);
}
bool intersect(const complex<double> &a, const complex<double> &b,
               const complex<double> &p, const complex<double> &q,
               complex<double> &ret) {
  double d1 = ((conj(p - a) * (b - a)).imag());
  double d2 = ((conj(q - a) * (b - a)).imag());
  ret = (d1 * q - d2 * p) / (d1 - d2);
  return fabs(d1 - d2) > 1e-9;
}
double getDistance(complex<double> a, complex<double> b) {
  return sqrt((a.real() - b.real()) * (a.real() - b.real()) +
              (a.imag() - b.imag()) * (a.imag() - b.imag()));
}
vector<int> start, fini;
long long acc[N * 3];
long long l[N * 3];
long long shiftlft(long long k, long long n) {
  if (k <= 0) return n;
  if (l[k] != -1) return (l[k] * n) % mod;
  long long shift = power(53ll, k);
  long long d = power(shift, mod - 2);
  l[k] = d;
  n *= d;
  return n % mod;
}
bool is[N * 2];
int main() {
  int n;
  scanf("%d", &n);
  memset(l, -1, sizeof(l));
  int sum = 0, len = 0;
  long long cur = 1;
  for (int i = (0); i <= (n - 1); ++i) {
    string s;
    cin >> s;
    if (i) s = " " + s;
    for (int j = (0); j <= ((int)s.length() - 1); ++j) {
      int idx = (s[j] - 'a') + 1;
      if (idx < 0) idx = 28;
      acc[len + j] = (idx)*cur;
      if (len + j) acc[len + j] += acc[len + j - 1];
      acc[len + j] %= mod;
      cur *= 53ll;
      cur %= mod;
    }
    sum += (int)s.length();
    start.push_back(len + (i > 0));
    len += s.length();
    fini.push_back(len - 1);
    is[len - 1] = 1;
  }
  int mn = sum;
  for (int i = (0); i <= ((int)start.size() - 1); ++i) {
    int words = 0;
    for (int j = (0); j <= ((int)fini.size() - 1); ++j) {
      if (fini[j] < start[i]) continue;
      words++;
      long long cur = acc[fini[j]];
      if (start[i]) {
        cur -= acc[start[i] - 1];
        cur += mod;
        cur %= mod;
      }
      cur = shiftlft(start[i], cur);
      int len = fini[j] - start[i] + 1, prv = fini[j], kam = 1;
      for (int k = (i + 1); k <= ((int)start.size() - 1); ++k) {
        if (start[k] <= prv) continue;
        if (start[k] + len - 1 >= sum) continue;
        if (!is[start[k] + len - 1]) continue;
        long long val = acc[start[k] + len - 1] - acc[start[k] - 1] + mod;
        val %= mod;
        val = shiftlft(start[k], val);
        if (cur == val) {
          kam++;
          prv = start[k] + len - 1;
        }
      }
      if (kam > 1) {
        mn = min(mn, sum - len * kam + words * kam);
      }
    }
  }
  cout << mn;
  return 0;
}
