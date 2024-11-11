#include <bits/stdc++.h>
using namespace std;
void solve(int test_number);
void pre() {
  cout.setf(ios::fixed);
  cout.precision(64);
  cerr.setf(ios::fixed);
  cerr.precision(3);
}
void post() {
  printf("\n");
  fprintf(stderr, "Execution time: %Lf", (long double)clock());
}
const int MAXN = 100100;
inline long double sqr(long double x) { return x * x; }
inline long double power(long double a, long long pow_) {
  if (pow_ == 1) return a;
  if (pow_ == 0) return 0.0;
  if (pow_ % 2 == 0) {
    return sqr(power(a, pow_ / 2));
  } else {
    return a * sqr(power(a, (pow_ - 1) / 2));
  }
}
inline void solve(int test_number) {
  long long n, t;
  scanf("%lld %lld", &n, &t);
  cout << n * power(1.000000011, t) << endl;
  return;
}
int main() {
  pre();
  int n = 1;
  for (int i = 0; i < n; i++) {
    solve(i + 1);
  }
  post();
  return 0;
}
