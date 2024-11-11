#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int a, b, c, d[111][11111], r[11111], rr[100007], n, m;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    memset(r, 0, sizeof(r));
    cin >> a;
    for (int j = 1; j <= a; j++) cin >> rr[j], rr[j] += rr[j - 1];
    for (int j = 1; j <= a; j++)
      for (int k = 0; k <= j; k++) umax(r[j], rr[k] + (rr[a] - rr[a - j + k]));
    for (int j = 1; j <= m; j++)
      for (int k = max(0, j - a); k <= j; k++)
        umax(d[i][j], d[i - 1][k] + r[j - k]);
  }
  cout << d[n][m] << endl;
  return 0;
}
