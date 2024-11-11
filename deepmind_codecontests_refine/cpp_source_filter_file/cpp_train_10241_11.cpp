#include <bits/stdc++.h>
using namespace std;
const int N = 500020;
long long int n;
struct point {
  long long int x, vel;
};
point ar[N];
point ar1[N];
point ar2[N];
long long int sz1 = 0, sz2 = 0;
bool comp(point a, point b) { return a.x < b.x; }
double tempans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> n;
  for (long long int i = 1; i <= n; i++) cin >> ar[i].x >> ar[i].vel;
  for (long long int i = 1; i <= n; i++) {
    if (ar[i].vel > 0)
      ar1[++sz1] = ar[i];
    else
      ar2[++sz2] = ar[i];
  }
  sort(ar + 1, ar + n + 1, comp);
  double ans = 1e9;
  double lo = 0.000000000, hi = 1e10;
  while (lo + 0.00000001 < hi) {
    double mid = (lo + hi) / 2;
    bool f = 0;
    double mmax = -1e40;
    for (long long int i = 1; i <= n; i++) {
      double pos = (double)ar[i].x + (double)ar[i].vel * mid;
      if (ar[i].vel > 0) {
        if (pos > mmax) mmax = pos;
      } else if (pos <= mmax) {
        f = 1;
        break;
      }
    }
    if (f)
      hi = mid;
    else
      lo = mid;
  }
  double mmax = -1e40;
  bool f = 0;
  for (long long int i = 1; i <= n; i++) {
    double pos = (double)ar[i].x + (double)ar[i].vel * lo;
    if (ar[i].vel > 0) {
      if (pos > mmax) mmax = pos;
    } else if (pos <= mmax) {
      f = 1;
      break;
    }
  }
  if (f) {
    printf("%0.9lf", lo);
    return 0;
  }
  f = 0;
  mmax = -1e40;
  for (long long int i = 1; i <= n; i++) {
    double pos = (double)ar[i].x + (double)ar[i].vel * hi;
    if (ar[i].vel > 0) {
      if (pos > mmax) mmax = pos;
    } else if (pos <= mmax) {
      f = 1;
      break;
    }
  }
  if (f) {
    printf("%0.9lf", hi);
    return 0;
  }
  cout << "-1" << endl;
  return 0;
}
