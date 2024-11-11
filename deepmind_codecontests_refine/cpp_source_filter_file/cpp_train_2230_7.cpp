#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T BIGMOD(T n, T m, T mod) {
  long long ans = 1;
  long long k = n;
  while (m) {
    if (m & 1) {
      ans *= k;
      if (ans > mod) ans %= mod;
    }
    k *= k;
    if (k > mod) k %= mod;
    m >>= 1;
  }
  return ans;
}
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <class T>
inline T power(T b, T p) {
  if (p < 0) return -1;
  if (b <= 0) return -2;
  if (!p) return 1;
  return b * power(b, p - 1);
}
template <typename T>
inline bool isOn(T mask, T pos) {
  return mask & (1 << pos);
}
template <typename T>
inline int Off(T mask, T pos) {
  return mask ^ (1 << pos);
}
template <typename T>
inline int On(T mask, T pos) {
  return mask | (1 << pos);
}
long long X;
int ar[200002];
int main() {
  int N, M, left = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> ar[i];
    if (ar[i] == 0) left++;
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (ar[i] == 1) ans += left;
    if (ar[i] == 0) left--;
  }
  cout << ans << endl;
  return 0;
}
