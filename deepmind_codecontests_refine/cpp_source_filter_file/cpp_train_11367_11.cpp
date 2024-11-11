#include <bits/stdc++.h>
using namespace std;
long long a[11], b[11], c[11];
void init() {
  a[1] = 9;
  b[1] = a[1];
  for (int i = 2; i <= 9; i++) {
    a[i] = i * (pow(10, i) - pow(10, i - 1));
    b[i] = b[i - 1] + a[i];
  }
  c[1] = 45;
  for (int i = 2; i <= 9; i++) {
    long long sum = (b[i] + b[i - 1] + i) * (pow(10, i) - pow(10, i - 1)) / 2;
    c[i] = c[i - 1] + sum;
  }
}
long long get_ans(long long x, long long p, long long t) {
  long long l = 1, r = pow(10, t) - pow(10, t - 1), sum;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    sum = (p + p + (mid - 1) * t) * mid / 2;
    if (sum == x) {
      return mid - 1;
    }
    if (sum < x) {
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return r;
}
void solve() {
  long long x;
  scanf("%lld", &x);
  int at = lower_bound(c + 1, c + 10, x) - c;
  x -= c[at - 1];
  long long p = b[at - 1] + at, t = at, ans1;
  ans1 = get_ans(x, p, t);
  x -= (2 * p + (ans1 - 1) * t) * ans1 >> 1;
  at = lower_bound(b + 1, b + 10, x) - b;
  x -= b[at - 1];
  long long y = pow(10, at - 1);
  if (x < at) {
  } else if (x % at == 0) {
    y = y + x / at - 1;
    x = at - 1;
  } else {
    y = y + x / at;
    x %= at;
    x--;
  }
  y /= pow(10, at - 1 - x);
  y %= 10;
  printf("%lld\n", y);
}
int main() {
  init();
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
