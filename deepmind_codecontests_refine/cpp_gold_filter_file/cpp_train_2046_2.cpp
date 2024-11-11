#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename T>
T pow(T a, T b, long long m) {
  T ans = 1;
  a = a % m;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans % m;
}
template <typename T>
T modInv(T a, T m) {
  return pow(a, m - 2, m);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int x2;
  cin >> x2;
  int a[1000005];
  for (int i = 2; i <= 1000001; i++) a[i] = i;
  for (int i = 2; i <= 1000; i++) {
    if (a[i] != i) continue;
    for (int x = 2 * i; x <= 1000000; x += i) a[x] = i;
  }
  for (int i = 1001; i <= 1000001; i++) {
    int c = a[i];
    int d = i;
    while (d > 1) {
      d = d / a[d];
      c = max(c, a[d]);
    }
    a[i] = c;
  }
  int l = x2 - a[x2] + 1;
  int x0 = x2;
  for (int x1 = l; x1 <= x2; x1++) {
    if (a[x1] == x1) continue;
    x0 = min(x0, x1 - a[x1] + 1);
  }
  cout << x0;
  return 0;
}
