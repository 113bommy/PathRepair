#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T gcd(T a, T b) {
  return (b != 0 ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return (a / gcd<T>(a, b) * b);
}
template <class T>
inline T bigmod(T p, T e, T M) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    long long int t = bigmod(p, e / 2, M);
    return (T)((t * t) % M);
  }
  return (T)((long long int)bigmod(p, e - 1, M) * (long long int)p) % M;
}
template <class T>
inline T bigexp(T p, T e) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    long long int t = bigexp(p, e / 2);
    return (T)((t * t));
  }
  return (T)((long long int)bigexp(p, e - 1) * (long long int)p);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
int dx4[] = {1, 0, -1, 0};
int dy4[] = {0, 1, 0, -1};
int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
int nx8[] = {1, 1, -1, -1, 2, 2, -2, -2};
int ny8[] = {2, -2, 2, -2, 1, -1, 1, -1};
int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int t;
int n, x, a[1005], p;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &x);
    memset(a, 0, sizeof a);
    for (__typeof(n) i = (1); i <= (n); i++) {
      scanf("%d", &p);
      a[p]++;
    }
    int res = 0;
    for (int i = 1; i <= 500; i++) {
      if (a[i] == 0) {
        if (x == 0)
          break;
        else
          x--;
      }
      res = i;
    }
    cout << res << endl;
  }
  return 0;
}
