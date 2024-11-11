#include <bits/stdc++.h>
double const EPS = 3e-8;
using namespace std;
template <class T>
T gcd(T a, T b) {
  return (b != 0 ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return (a / gcd<T>(a, b) * b);
}
template <class T>
inline bool read(T &x) {
  int c = getchar();
  int sgn = 1;
  while (~c && c < '0' || c > '9') {
    if (c == '-') sgn = -1;
    c = getchar();
  }
  for (x = 0; ~c && '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  x *= sgn;
  return ~c;
}
const int NX = 1e6 + 10;
long long inp[NX];
int n, k;
long long x;
long long has[34];
int main() {
  long long mx = -1;
  n = ({
    int a;
    read(a);
    a;
  }),
  k = ({
    int a;
    read(a);
    a;
  }),
  x = ({
    long long a;
    read(a);
    a;
  });
  int pos;
  long long tmp = 0;
  for (__typeof((n)-1) i = (0); i <= (n)-1; ++i) {
    inp[i] = ({
      long long a;
      read(a);
      a;
    });
    tmp |= inp[i];
    for (long long j = 0; j <= 32; j++) {
      if (inp[i] & (1ll << j)) has[j]++;
    }
  }
  long long mul = k * x;
  long long ans = 0;
  for (__typeof((n)-1) i = (0); i <= (n)-1; ++i) {
    mul = inp[i];
    for (__typeof((k)-1) j = (0); j <= (k)-1; ++j) {
      mul *= x;
    }
    long long a = tmp;
    for (long long j = 0; j <= 32; j++) {
      if (inp[i] & (1ll << j)) {
        if (has[j] == 1) a ^= (1ll << j);
      }
    }
    ans = max(ans, (a) | (mul));
  }
  cout << ans << endl;
  return 0;
}
