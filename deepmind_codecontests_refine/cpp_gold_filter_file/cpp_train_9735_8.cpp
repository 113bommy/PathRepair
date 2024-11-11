#include <bits/stdc++.h>
using namespace std;
inline int input() {
  int a;
  cin >> a;
  return a;
}
template <typename T>
inline void output(T a, int p) {
  if (p) {
    cout << fixed << setprecision(p) << a << "\n";
  } else {
    cout << a << "\n";
  }
}
long long pow_mod(long long a, long long b, long long mod) {
  long long ret = 1;
  while (b > 0) {
    if (b & 1) {
      ret = ret * a % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
int main() {
  cin.tie(0);
  long long P, K;
  cin >> P >> K;
  if (K == 0) {
    long long ret = pow_mod(P, P - 1, 1000000007);
    output(ret, 0);
    return 0;
  }
  if (K == 1) {
    long long ret = pow_mod(P, P, 1000000007);
    output(ret, 0);
    return 0;
  }
  long long ret = P;
  for (int i = 2; i <= P - 1; i++) {
    if ((P - 1) % i == 0) {
      if (pow_mod(K, i, P) == 1) {
        ret = pow_mod(P, (P - 1) / i, 1000000007);
        break;
      }
    }
  }
  output(ret, 0);
  return 0;
}
