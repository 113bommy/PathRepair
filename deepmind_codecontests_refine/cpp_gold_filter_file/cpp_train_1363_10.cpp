#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
const long long mod = 1e9 + 7;
const double eps = 1e-8;
const long long MAX = 1e7 + 20;
template <class T>
T gcd(T a, T b) {
  return (b != 0 ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return (a / gcd<T>(a, b) * b);
}
inline const int EQ(double tmp) {
  if (fabs(tmp) < eps) return 0;
  return tmp > eps ? 1 : -1;
}
long long BM(long long B, long long P, long long M) {
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
long long MI(long long x, long long m) { return BM(x, m - 2, m); }
inline int LEFT(int x) { return (x << 1); }
inline int RIGHT(int x) { return (x << 1) + 1; }
double num[50005];
int main() {
  double n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  double mx = 0;
  for (int i = k; i <= n; i++) {
    int prev = 1;
    double tot = 0;
    for (int j = 1; j <= n; j++) {
      if (j <= i)
        tot += num[j];
      else {
        tot -= num[prev];
        tot += num[j];
        prev++;
      }
      if (j >= i) {
        double now = (tot / (double)i);
        mx = max(mx, now);
      }
    }
  }
  printf("%.10f\n", mx);
  return 0;
}
