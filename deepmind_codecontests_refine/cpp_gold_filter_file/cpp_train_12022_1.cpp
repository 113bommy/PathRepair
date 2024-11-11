#include <bits/stdc++.h>
using namespace std;
double gp1(long long l, long long r, long long x) {
  if (l <= x && x <= r) {
    return ((double)(r - x)) / ((double)(r - l + 1));
  } else if (x < l) {
    return 1.0;
  }
  return 0.0;
}
double lp1(long long l, long long r, long long x) {
  if (l <= x && x <= r) {
    return ((double)(x - l)) / ((double)(r - l + 1));
  } else if (x < l) {
    return 0.0;
  }
  return 1.0;
}
double eq1(long long l, long long r, long long x) {
  if (l <= x && x <= r) {
    return (1.0) / (double(r - l + 1));
  } else if (x < l) {
    return 0.0;
  }
  return 0.0;
}
int main() {
  long long n;
  cin >> n;
  vector<long long> l1;
  vector<long long> r1;
  for (long long i = 0; i < n; ++i) {
    long long lx, rx;
    cin >> lx >> rx;
    l1.push_back(lx);
    r1.push_back(rx);
  }
  double ans = 0, p_total = 0;
  for (long long k = 1; k <= 10000; ++k) {
    double p = 0;
    for (long long i = 0; i < n; ++i) {
      double p1_1 = gp1(l1[i], r1[i], k);
      double p1_2 = eq1(l1[i], r1[i], k);
      double p2 = 1, p3 = 1;
      for (long long j = 0; j < n; ++j) {
        if (j == i) {
          continue;
        }
        p2 = (lp1(l1[j], r1[j], k) + eq1(l1[j], r1[j], k)) * p2;
        p3 = (lp1(l1[j], r1[j], k)) * p3;
      }
      p = p + p1_1 * (p2 - p3);
      p = p - p1_2 * p3;
    }
    double p2 = 1, p3 = 1;
    for (long long j = 0; j < n; ++j) {
      p2 = (lp1(l1[j], r1[j], k) + eq1(l1[j], r1[j], k)) * p2;
      p3 = (lp1(l1[j], r1[j], k)) * p3;
    }
    p = p + (p2 - p3);
    p_total = p_total + p;
    ans = ans + p * k;
  }
  printf("%.10lf", ans);
  return 0;
}
