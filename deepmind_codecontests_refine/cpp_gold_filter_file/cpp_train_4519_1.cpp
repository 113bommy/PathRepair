#include <bits/stdc++.h>
const int Mod = 1000000007;
const double eps = 1e-8;
const long long inf = 1e18;
const int inf1 = 1e9;
const int N = 100005;
using namespace std;
double x[2005];
int s[2005];
struct po {
  long long n, sum;
} p[200005];
double mul(long long n, long long N, long long k) {
  long long i;
  if (s[n] == 0) {
    double a = (double)n, b = (double)N, c = (double)k, d = 1.0;
    for (i = 0; i < k; ++i) d *= ((a - (double)i) / (b - (double)i));
    x[n] = d * c / a;
    s[n] = 1;
    return x[n];
  } else
    return x[n];
}
int main() {
  long long n, i, j, k, x;
  double y = 0;
  long long sum = 0;
  memset(p, 0, sizeof(p));
  cin >> n >> k;
  for (i = 0; i < n; ++i)
    for (j = i + 1; j < n; ++j) {
      scanf("%I64d", &x);
      if (x != -1) {
        p[i].n++;
        p[j].n++;
        p[i].sum += x;
        p[j].sum += x;
      }
    }
  for (i = 0; i < n; ++i) {
    if (p[i].n >= k) y += (mul(p[i].n, n, k) * (double)p[i].sum * 10000.0);
  }
  cout << (long long)((y + 0.5) / 10000.0) << endl;
  return 0;
}
