#include <bits/stdc++.h>
#pragma GCC target("avx,avx2,fma")
using namespace std;
template <typename T>
int len(const T& a) {
  return a.size();
}
using ll = long long;
constexpr int N = 2e5 + 10;
constexpr long double EPS = 1e-7;
int n;
int a[N];
long double Check(long double x) {
  static long double new_a[N];
  long double bestmin = 1e8, curmin = 0;
  long double bestmax = -1e8, curmax = 0;
  for (int i = 0; i < n; ++i) {
    new_a[i] = (long double)a[i] - x;
    curmax = max((long double)0, curmax + new_a[i]);
    bestmax = max(bestmax, curmax);
    curmin = min((long double)0, curmin + new_a[i]);
    bestmin = min(bestmin, curmin);
  }
  return max(abs(bestmin), abs(bestmax));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  long double l = -1e4 - 10, r = 1e4 + 10;
  for (int step = 0; step < 200; ++step) {
    long double m1 = l + (r - l) / 3.0;
    long double m2 = r - (r - l) / 3.0;
    if (Check(m1) - Check(m2) > EPS) {
      l = m1;
    } else {
      r = m2;
    }
  }
  printf("%.6Lf", Check(l));
  return 0;
}
