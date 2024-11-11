#include <bits/stdc++.h>
using namespace std;
template <typename T>
T Abs(T x) {
  return x > 0 ? x : -x;
}
template <typename T>
T const& Max(T const& a, T const& b) {
  return a > b ? a : b;
}
template <typename T>
T const& Min(T const& a, T const& b) {
  return a < b ? a : b;
}
template <typename T>
inline T gcd(T a, T b) {
  return (b ? gcd(b, a % b) : a);
}
template <typename T>
T sqaa(T a) {
  return a * a;
}
long long int modPow(long long int a, long long int pow, long long int mod) {
  if (!pow)
    return 1;
  else if (pow & 1)
    return (a * modPow(a, pow - 1, mod)) % mod;
  else {
    long long int ret = modPow(a, pow >> 1, mod) % mod;
    return (ret * ret) % mod;
  }
}
long long int modINV(long long int a, long long int M) {
  return modPow(a, M - 2, M);
}
int ar[4];
bool tri() {
  for (int i = (0); i < (4); i++) {
    for (int j = (0); j < (4); j++) {
      if (i == j) continue;
      for (int k = (0); k < (4); k++) {
        if (k == i || k == j) continue;
        if (ar[k] + ar[j] > ar[i] && ar[k] + ar[i] > ar[j] &&
            ar[i] + ar[j] > ar[k]) {
          return true;
        }
      }
    }
  }
  return false;
}
bool de() {
  for (int i = (0); i < (4); i++) {
    for (int j = (0); j < (4); j++) {
      if (i == j) continue;
      for (int k = (0); k < (4); k++) {
        if (k == i || k == j) continue;
        if (ar[k] + ar[j] >= ar[i] && ar[k] + ar[i] >= ar[j] &&
            ar[i] + ar[j] >= ar[k]) {
          return true;
        }
      }
    }
  }
  return false;
}
int main() {
  while (cin >> ar[0] >> ar[1] >> ar[2] >> ar[3]) {
    if (tri()) {
      cout << "TRIANGLE\n";
    } else if (de()) {
      cout << "SEGMENT\n";
    } else {
      cout << "IMPOSSILBE\n";
    }
  }
  return 0;
}
