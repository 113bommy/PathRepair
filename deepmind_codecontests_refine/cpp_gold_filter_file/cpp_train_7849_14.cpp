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
int prime[8] = {2, 3, 5, 7, 11, 13, 17, 19};
int ar[100001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a = 0, b, c, d, e = 0, f = 0, g, h = 0, x, y, z;
  cin >> a;
  for (int i = 0; e < a && i < 8; i++) {
    ar[e++] = prime[i];
    for (int j = 0; j < e; j++) {
      if (ar[j] * prime[i] <= 2 * a * a) ar[e++] = ar[j] * prime[i];
    }
  }
  for (int i = e - 1; i >= e - a; i--) {
    cout << ar[i] << " ";
  }
  cout << endl;
}
