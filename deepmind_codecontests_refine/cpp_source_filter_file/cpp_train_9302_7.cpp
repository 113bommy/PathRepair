#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b);
long long cross_prod(long long ax, long long ay, long long bx, long long by,
                     long long cx, long long cy);
long long sum_digit(long long A);
long long get_mask(long long x);
int N, D, L;
int V[102];
int main() {
  int i, j, sum = 0, x;
  cin >> N >> D >> L;
  for (i = 1; i <= N; ++i) {
    if (D < 0) {
      V[i] = 1;
    } else {
      V[i] = L;
    }
    D = V[i] - D;
  }
  V[N] -= D;
  if (V[N] < 1 || V[N] > L) {
    cout << -1;
  } else {
    for (i = 1; i <= N; ++i) {
      cout << V[i] << ' ';
    }
  }
  return 0;
}
long long gcd(long long a, long long b) { return (b ? gcd(b, a % b) : a); }
long long cross_prod(long long ax, long long ay, long long bx, long long by,
                     long long cx, long long cy) {
  return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
}
long long sum_digit(long long A) {
  long long sum = 0;
  do {
    sum += A % 10;
    A /= 10;
  } while (A);
  return sum;
}
long long get_mask(long long x) {
  long long mask = 0, c;
  while (x) {
    c = x % 10;
    x /= 10;
    if (c == 4 || c == 7) {
      mask = mask * 10 + c;
    }
  }
  return mask;
}
