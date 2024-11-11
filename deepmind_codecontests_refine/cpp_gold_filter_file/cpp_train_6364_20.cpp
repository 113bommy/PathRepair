#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T GCD(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
template <typename T>
inline T LCM(T x, T y) {
  T tp = GCD(x, y);
  if ((x / tp) * 1. * y > 9e18) return 9e18;
  return (x / tp) * y;
}
template <typename T>
inline T BigMod(T A, T B, T M) {
  T ret = 1;
  while (B) {
    if (B & 1) ret = (ret * A) % M;
    A = (A * A) % M;
    B = B >> 1;
  }
  return ret;
}
template <typename T>
inline T InvMod(T A, T M) {
  return BigMod(A, M - 2, M);
}
long long gcdr(long long a, long long b) {
  if (a == 0) return b;
  return gcdr(b % a, a);
}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
void FastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
}
const long long size3 = 300005;
const long long size2 = 200005;
const long long size1 = 100005;
int main() {
  long long t, i, j, m, x, y, n;
  t = 1;
  while (t--) {
    scanf("%lld", &n);
    vector<long long> V;
    for (i = 0; i < n; i++) {
      scanf("%lld", &x);
      V.push_back(x);
    }
    long long ansT, ansM = 1e15;
    for (i = 1; i <= 200; i++) {
      long long cost = 0;
      for (j = 0; j < n; j++) {
        long long tt = abs((abs(V[j] - i)));
        if (tt > 1) {
          cost += (tt - 1);
        }
      }
      if (cost < ansM) {
        ansT = i;
        ansM = cost;
      }
    }
    printf("%lld", ansT);
    printf(" ");
    printf("%lld", ansM);
    printf("\n");
  }
  return 0;
}
