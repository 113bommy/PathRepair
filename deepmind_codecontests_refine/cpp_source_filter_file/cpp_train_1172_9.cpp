#include <bits/stdc++.h>
using namespace std;
int cnt(int a, int b) {
  if (a % b == 0) {
    return a / b;
  } else
    return a / b + 1;
}
int main() {
  int n, m;
  int l[505], w[505], h[505];
  int wp[505], lp[505], price[505];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> w[i] >> h[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> wp[i] >> lp[i] >> price[i];
  }
  int s1, s2;
  int onepri, minpri;
  int sumpri = 0;
  for (int i = 0; i < n; i++) {
    minpri = 0x3F3F3F3F;
    for (int j = 0; j < m; j++) {
      if (wp[j] > h[i]) {
        s1 = wp[j] / h[i] * lp[j];
        s2 = (l[i] + w[i]) * 2;
        onepri = cnt(s2, s1) * price[j];
        minpri = min(minpri, onepri);
      }
    }
    sumpri += minpri;
  }
  cout << sumpri;
  return 0;
}
