#include <bits/stdc++.h>
using namespace std;
inline long long int modadd(long long int n, long long int m,
                            long long int p = 1000000007) {
  return ((n + m) % p + p) % p;
}
inline long long int modsub(long long int n, long long int m,
                            long long int p = 1000000007) {
  return ((n - m + p) % p + p) % p;
}
inline long long int modpro(long long int n, long long int m,
                            long long int p = 1000000007) {
  return (((n % p) * (m % p)) % p + p) % p;
}
unsigned long long int powe(long long int first, long long int second) {
  unsigned long long int res = 1;
  while (second > 0) {
    if (second & 1) res = res * first;
    second = second >> 1;
    first = first * first;
  }
  return res;
}
long long int modpow(long long int first, long long int second,
                     long long int p = 1000000007) {
  long long int res = 1;
  while (second > 0) {
    if (second & 1) res = modpro(res, first, p);
    second = second >> 1;
    first = modpro(first, first, p);
  }
  return res;
}
inline long long int modInverse(long long int n, long long int p = 1000000007) {
  if (n == 1) return 1;
  return modpow(n, p - 2, p);
}
inline long long int moddiv(long long int n, long long int m,
                            long long int p = 1000000007) {
  return modpro(n, modInverse(m, p), p);
}
inline long long int modadd3(long long int first, long long int second,
                             long long int z, long long int p = 1000000007) {
  return modadd(modadd(first, second, p), z, p);
}
inline long long int modadd4(long long int first, long long int second,
                             long long int z, long long int w,
                             long long int p = 1000000007) {
  return modadd(modadd(first, second, p), modadd(z, w, p), p);
}
inline long long int modnCr(long long int fac[], int n, int r,
                            long long int p = 1000000007) {
  if (r == 0) return 1;
  return modpro(fac[n], modInverse(modpro(fac[r], fac[n - r], p), p), p);
}
template <typename T>
inline T max3(T first, T second, T z) {
  return max(max(first, second), z);
}
template <typename T>
inline T max4(T first, T second, T z, T w) {
  return max(max3(first, second, w), z);
}
template <typename T>
inline T min3(T first, T second, T z) {
  return min(min(first, second), z);
}
template <typename T>
inline T min4(T first, T second, T z, T w) {
  return min(min3(first, second, w), z);
}
template <typename T>
void printArr(T *arr, int s, int n) {
  for (int i = s; i <= n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
string s;
long long int a[200005];
long long int ps[200005];
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int erer = 1;
  for (int erer2 = (1); erer2 < (erer + 1); erer2++) {
    cin >> s;
    int n = ((long long int)(s).size());
    int m;
    cin >> m;
    for (int i = (0); i < (n); i++) {
      a[i] = s[i] - '0';
      ps[i + 1] = ps[i] * 10 + a[i];
      ps[i + 1] %= m;
    }
    long long int small = INT_MAX;
    for (int i = (0); i < (n); i++) {
      if (!a[i]) continue;
      long long int rem =
          modadd(modpro(ps[n] - modpro(ps[i], modpow(10, n - i, m), m),
                        modpow(10, i, m), m),
                 ps[i], m);
      small = min(small, rem);
    }
    cout << small << endl;
  }
  return 0;
}
