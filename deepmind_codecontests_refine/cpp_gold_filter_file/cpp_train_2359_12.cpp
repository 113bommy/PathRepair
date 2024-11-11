#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
long long c[50];
long long calc(long long u) {
  if (u == 0) return 0;
  if (u == 1) return 1;
  if (u == 2) return 3;
  if (u == 3) return 4;
  int i = 63 - __builtin_clzll(u);
  long long first = (1LL << i);
  long long sum = 0;
  sum += calc(u - first) + c[i] + first;
  return sum;
}
int main() {
  c[1] = 1;
  c[2] = 4;
  for (int i = 3; i < 50; i++) {
    c[i] = 2 * c[i - 1] + (1LL << (i - 1));
  }
  long long n;
  scanf("%I64d", &n);
  cout << calc(n - 1) << endl;
}
