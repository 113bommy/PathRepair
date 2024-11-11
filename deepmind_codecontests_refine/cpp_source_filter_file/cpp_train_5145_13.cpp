#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000007;
template <class T>
T bigmod(T b, T p, T m) {
  if (p == 0) return 1;
  T res = bigmod(b, p / 2, m);
  res = (res * res) % m;
  if (p % 2 == 1) res = (res * b) % m;
  return res;
}
template <class T>
T gcd(T x, T y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
template <typename T>
T modinv(T num, T m) {
  return bigmod(num, m - 2, m);
}
long long a[500005];
int main() {
  long long i, j, k, l, m, n;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  j = n / 2 + 1;
  long long count = 0;
  for (i = 0; i < n / 2; i++) {
    for (; j < n; j++) {
      if (a[j] >= (2 * a[i])) {
        count++;
        j++;
        break;
      }
    }
  }
  cout << n - count << endl;
  return 0;
}
