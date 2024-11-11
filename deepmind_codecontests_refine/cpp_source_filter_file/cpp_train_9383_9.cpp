#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7, M = 2e6;
const long long mod = 1e9 + 7;
inline int read() {
  int ret = 0;
  char ch = getchar();
  bool f = 1;
  for (; !isdigit(ch); ch = getchar()) f ^= !(ch ^ '-');
  for (; isdigit(ch); ch = getchar()) ret = (ret << 1) + (ret << 3) + ch - 48;
  return f ? ret : -ret;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long ksm(long long a, long long b, long long mod) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
long long inv2(long long a, long long mod) { return ksm(a, mod - 2, mod); }
double Min(double x, double y) {
  if (x < y) return x;
  return y;
}
double a[N], arr[N];
int main() {
  int n;
  double m, k;
  scanf("%d%lf%lf", &n, &k, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &a[i]);
  }
  sort(a + 1, a + 1 + n);
  arr[0] = 0.0;
  for (int i = 1; i <= n; i++) {
    arr[i] = arr[i - 1] + a[i];
  }
  double ti;
  double ans = 0.0;
  for (int i = 1; i < n; i++) {
    ti = m - i;
    if (ti < 0) break;
    double sum = arr[n] - arr[i];
    sum += Min((double)(n - i) * k, ti);
    sum = sum / (double)(n - i);
    if (ans < sum) ans = sum;
  }
  printf("%.10f\n", ans);
  return 0;
}
