#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000 * 1000 + 100, inf = 1000 * 1000 * 10;
int A[MAX_N], n;
const double eps = 1e-4;
int valid(double c) {
  double d = c;
  for (int i = 1; i <= n; ++i) {
    d -= 10 * (A[i] - A[i - 1]);
    if (d > 10) return -1;
    if (d < 0) return 1;
    d += c;
  }
  return 0;
}
int main() {
  cin >> n;
  A[0] = 0;
  for (int i = 1; i <= n; ++i) cin >> A[i];
  double l = 10, r = MAX_N - 10;
  A[n + 1] = inf;
  while (l + eps < r) {
    double c = (l + r) / 2;
    int b = valid(c);
    if (!b) {
      l = c;
      break;
    }
    if (b < 0)
      r = c;
    else
      l = c;
  }
  double d = l;
  for (int i = 1; i <= n; ++i) d -= 10 * (A[i] - A[i - 1]), d += l;
  A[n + 1] = A[n] + int(trunc(double(d / 10)));
  int res = A[n + 1];
  ++n;
  --A[n];
  l = 10, r = MAX_N - 10;
  while (l + eps < r) {
    double c = (l + r) / 2;
    int b = valid(c);
    if (!b) {
      l = c;
      break;
    }
    if (b < 0)
      r = c;
    else
      l = c;
  }
  if (!valid(l)) {
    cout << "not unique";
    return 0;
  }
  A[n] += 2;
  l = 10, r = MAX_N - 10;
  while (l + eps < r) {
    double c = (l + r) / 2;
    int b = valid(c);
    if (!b) {
      l = c;
      break;
    }
    if (b < 0)
      r = c;
    else
      l = c;
  }
  if (!valid(l))
    cout << "not unique";
  else
    cout << "unique" << endl << res;
  return 0;
}
