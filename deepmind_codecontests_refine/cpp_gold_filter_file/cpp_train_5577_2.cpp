#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
long long min(long long a, long long b, long long c) {
  return min(a, min(b, c));
}
int main(int argc, char const *argv[]) {
  long long a, b, c, n;
  cin >> n >> a >> b >> c;
  int r = n % 4;
  switch (r) {
    case 0: {
      cout << 0;
      break;
    };
    case 1: {
      cout << min(c, 3 * a, b + a);
      break;
    };
    case 2: {
      cout << min(b, 2 * a, 2 * c);
      break;
    };
    case 3: {
      cout << min(a, b + c, 3 * c);
      break;
    };
  }
  return 0;
}
