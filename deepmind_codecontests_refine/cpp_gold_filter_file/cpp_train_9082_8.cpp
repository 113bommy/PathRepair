#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int next_x[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int next_y[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int inf = 1e9 + 5;
const long long linf = 1e18;
const double PI = acos(-1.0);
const int MAXN = 500 + 5;
const int N = 20000;
long long l, r, m, a, b, c;
bool check(long long &a, long long &b, long long &c) {
  if (m % a == 0) {
    b = r, c = r;
    return 1;
  }
  long long k = m / a;
  if (k && m - k * a <= r - l) {
    long long t = m - k * a;
    b = r, c = r - t;
    return 1;
  }
  if ((k + 1) * a - m <= r - l) {
    long long t = (k + 1) * a - m;
    b = r - t, c = r;
    return 1;
  }
  return 0;
}
int work() {
  int _CASE;
  scanf("%d", &_CASE);
  for (register int case_num = (1), I = (_CASE) + 1; case_num < I; ++case_num) {
    cin >> l >> r >> m;
    for (register int i = (l), I = (r) + 1; i < I; ++i) {
      a = i;
      if (check(a, b, c)) {
        printf("%lld %lld %lld\n", a, b, c);
        break;
      }
    }
  }
  return 0;
}
int main() {
  work();
  return 0;
}
