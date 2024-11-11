#include <bits/stdc++.h>
using namespace std;
int setBit(int n, int r) { return n | (1 << r); }
int resetBit(int n, int r) { return n & ~(1 << r); }
int checkBit(int n, int r) { return n & (1 << r); }
template <typename T>
T mod(T a, T b = 1000000007) {
  return (a % b) >= 0 ? (a % b) : (a % b) + b;
}
template <typename T>
T bigmod(T p, T e, T M) {
  T ret = 1;
  while (e > 0) {
    if (e % 2) ret = (ret * p) % M;
    p = (p * p) % M;
    e /= 2;
  }
  return ret;
}
template <typename T>
T power(T x, T y) {
  T ans = 1;
  while (y > 0) {
    if (y % 2) ans *= x;
    x *= x;
    y /= 2;
  }
  return ans;
}
template <typename T>
T gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b != 0) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
template <typename T>
T lcm(T a, T b) {
  return a * (b / gcd(a, b));
}
template <typename T>
void read(T &result) {
  bool sgn = false;
  result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  if (ch == '-')
    sgn = true;
  else
    result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }
  if (sgn) result = -result;
}
int r, n, a[(int)1e5 + 5], b[(int)1e5 + 5];
bool ask(int i, int mid) {
  int x = a[i - 1] + abs(mid - b[i - 1]);
  int y = a[i] - abs(mid - b[i]);
  return x <= y;
}
int bs(int i) {
  int lo = max(b[i], b[i - 1]);
  int hi = 200000005;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (ask(i, mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  return lo;
}
int main() {
  read(r);
  read(n);
  for (int i = 0; i < n; i++) {
    read(a[i]);
    read(b[i]);
  }
  int best = max(a[0] - 1 + b[0], r - a[n - 1] + b[n - 1]);
  for (int i = 1; i <= n - 1; i++) {
    int dif = a[i] - a[i - 1];
    int vDif = abs(b[i] - b[i - 1]);
    if (dif - vDif < 0) return 0 * printf("IMPOSSIBLE");
    best = max(best, bs(i));
  }
  cout << best;
}
