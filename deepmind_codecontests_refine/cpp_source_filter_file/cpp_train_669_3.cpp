#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;
using namespace std;
long long inv(long long a, long long b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
long long Pow(long long B, long long P) {
  long long R = 1;
  while (P > 0) {
    if (P & 1) R = (R * B);
    P /= 2;
    B = (B * B);
  }
  return R;
}
long long GCD(long long a, long long b) {
  while (b) {
    b ^= a ^= b ^= a %= b;
  }
  return a;
}
long long LCM(long long a, long long b) { return (a / GCD(a, b) * b); }
long long BigMod(long long B, long long P, long long M) {
  long long R = 1;
  while (P > 0) {
    if (P & 1) {
      R = (R * B) % M;
    }
    P /= 2;
    B = (B * B) % M;
  }
  return (long long)R;
}
int ans = OO;
complex<double> reflect(complex<double> p, complex<double> p0,
                        complex<double> p1) {
  complex<double> z = p - p0, w = p1 - p0;
  return conj(z / w) * w + p0;
}
double dcmp(double a, double b) {
  return fabs(a - b) <= 1e-9 ? 0 : a < b ? -1 : 1;
}
bool samepoint(complex<double> a, complex<double> b) {
  return (dcmp(a.real(), b.real()) == 0) && (dcmp(a.imag(), b.imag()) == 0);
}
bool sq(complex<double> a, complex<double> b, complex<double> c,
        complex<double> d) {
  bool k = (samepoint(a, b) == 0) && (samepoint(a, c) == 0) &&
           (samepoint(a, d) == 0) && (samepoint(b, c) == 0) &&
           (samepoint(b, d) == 0) && (samepoint(c, d) == 0);
  if (!k) return 0;
  if (dcmp(((conj(((c) - (a))) * (((d) - (a)))).real()), 0) == 0 &&
      samepoint(b, reflect(a, c, d)))
    return 1;
  if (dcmp(((conj(((b) - (a))) * (((d) - (a)))).real()), 0) == 0 &&
      samepoint(c, reflect(a, b, d)))
    return 1;
  if (dcmp(((conj(((c) - (a))) * (((b) - (a)))).real()), 0) == 0 &&
      samepoint(d, reflect(a, c, b)))
    return 1;
  return 0;
}
vector<pair<complex<double>, complex<double>>> ps;
long long dfs(int pos) {
  if (pos == 4) {
    if (sq(ps[0].second, ps[1].second, ps[2].second, ps[3].second)) {
      return 0LL;
    }
    return OO;
  }
  long long ans = dfs(pos + 1);
  for (long long i = 0; i < 3; ++i) {
    ps[pos].second = (((((ps[pos].second) - (ps[pos].first))) *
                       exp(complex<double>(0, acos(-1.0) / 2))) +
                      ps[pos].first);
    ans = min(ans, dfs(pos + 1) + i + 1);
  }
  ps[pos].second = (((((ps[pos].second) - (ps[pos].first))) *
                     exp(complex<double>(0, acos(-1.0) / 2))) +
                    ps[pos].first);
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    ps.clear();
    for (long long i = 0; i < 4; ++i) {
      double xi, yi, ai, bi;
      cin >> xi >> yi >> ai >> bi;
      complex<double> p1(xi, yi), p2(ai, bi);
      ps.push_back({p2, p1});
    }
    int ans = dfs(0);
    cout << (ans >= OO ? -1 : ans) << "\n";
  }
  return 0;
}
