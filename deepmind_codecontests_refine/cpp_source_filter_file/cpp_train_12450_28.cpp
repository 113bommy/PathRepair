#include <bits/stdc++.h>
using namespace std;
const int N = 123456;
long double a[N], b[N];
int n;
long double p;
bool check(long double mid) {
  long double timeNeeded = 0.0;
  for (int i = 0; i < n; i++) {
    timeNeeded += max((long double)0.0, (a[i] * mid - b[i]) / p);
  }
  return timeNeeded <= mid;
}
int main() {
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  long double lo = 0, hi = 1e11;
  for (int i = 0; i < 300; i++) {
    long double mid = (lo + hi) * 0.5;
    if (check(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  if (hi == (long double)1e11)
    cout << -1 << endl;
  else
    cout << fixed << setprecision(10) << lo << endl;
  return 0;
}
