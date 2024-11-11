#include <bits/stdc++.h>
using namespace std;
int n, p;
int a[100005], b[100005];
const long double EPS = 1e-8;
inline void read(int &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = 10 * x + c - '0';
    c = getchar();
  }
  x *= f;
}
inline int ok(long double time) {
  long double Spare = time * p;
  for (int i = (1); i <= (n); i++)
    if (time * a[i] - b[i] > -EPS) {
      Spare -= (time * a[i] - b[i]);
      if (Spare < EPS) return 0;
    }
  return 1;
}
int main() {
  read(n);
  read(p);
  for (int i = (1); i <= (n); i++) read(a[i]), read(b[i]);
  long long tot = 0;
  for (int i = (1); i <= (n); i++) tot += a[i];
  long long totb = 0;
  for (int i = (1); i <= (n); i++) totb += b[i];
  if (tot <= p) {
    puts("-1");
    return 0;
  }
  long double l = 0, r = (long double)totb / (tot - p);
  while ((r - l) > EPS) {
    long double mid = (l + r) / 2;
    if (ok(mid))
      l = mid;
    else
      r = mid;
  }
  long double ans = (l + r) / 2;
  printf("%.10lf", (double)ans);
  return 0;
}
