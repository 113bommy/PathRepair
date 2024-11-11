#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%I64d", &x);
  return x;
}
long long n;
inline long long GCD(long long a, long long b) {
  while (a > 0 && b > 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}
int P(long long x) {
  if (x == 2) return 1;
  if (x % 2 == 0) return 0;
  for (long long a = 3; a * a <= x; a = a + 2) {
    if (x % a == 0) {
      return 0;
    }
  }
  return 1;
}
void Solve() {
  if (n == 2) {
    cout << 1 << "/" << 6 << '\n';
    return;
  }
  if (P(n + 1)) {
    long long a = n - 1;
    long long b = n + n + 2;
    long long c = GCD(a, b);
    cout << a / c << "/" << b / c << '\n';
    return;
  }
  long long u = n, v = n + 1, w;
  while (!P(u)) u--;
  while (!P(v)) v++;
  w = n - u + 1;
  long long a = u * v - 2ll * v + 2ll * w;
  long long b = 2ll * u * v;
  long long c = GCD(a, b);
  cout << a / c << "/" << b / c << '\n';
}
int main() {
  int test = in();
  while (test--) {
    n = lin();
    Solve();
  }
  return 0;
}
