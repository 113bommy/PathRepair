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
int ar[666][666];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int Q;
  cin >> Q;
  while (Q--) {
    int H, W;
    cin >> H >> W;
    for (int i = (0); i < (H); ++i)
      for (int j = (0); j < (W); ++j) cin >> ar[i][j];
    int v = H / 2;
    int cnt = 0;
    for (int i = (0); i < (W); ++i) {
      if (abs(ar[v][i] - ar[v + 1][i]) > 70) cnt++;
    }
    if (cnt * 2 > W)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
