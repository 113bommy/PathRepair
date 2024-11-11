#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > v;
double a[1000];
int n, k;
long long x, y;
static const long long MAX = 1000000000000000000;
inline long long min(long long a, long long b) { return a < b ? a : b; }
inline long long max(long long a, long long b) { return a > b ? a : b; }
double how_prob_is_one_firts(long long l, long long r) {
  long long d = 1, cl, cr, c1, c2;
  double res = 0;
  while (d != MAX && d * 10 <= r) d *= 10;
  if (l < d) {
    cl = d - l;
    cr = r - d + 1;
  } else {
    cl = 0;
    cr = r - l + 1;
  }
  if (cl) res += how_prob_is_one_firts(l, d - 1) * double(cl) / double(cl + cr);
  l = max(l, d);
  d *= 2;
  if (l < d) {
    c1 = min(r + 1, d) - l;
    c2 = max(r - d + 1, 0);
  } else {
    c1 = 0;
    c2 = r - l + 1;
  }
  res += double(c1) / double(c1 + c2) * cr / double(cl + cr);
  return res;
}
double b[1000][1002];
int main() {
  cin >> n;
  for (int i = int(0); i < int(n); ++i) {
    cin >> x >> y;
    a[i] = how_prob_is_one_firts(x, y);
  }
  cin >> k;
  b[0][1] = a[0];
  b[0][0] = 1 - a[0];
  for (int i = int(1); i < int(n); ++i) {
    for (int j = int(0); j < int(i + 1); ++j) {
      b[i][j] += b[i - 1][j] * (1 - a[i]);
      b[i][j + 1] += b[i - 1][j] * (a[i]);
    }
  }
  double res = 0;
  int p = n;
  while (p * 100 / n >= k) {
    res += b[n - 1][p];
    --p;
  }
  printf("%0.10lf", res);
  return 0;
}
