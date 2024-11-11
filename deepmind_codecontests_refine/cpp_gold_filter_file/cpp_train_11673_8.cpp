#include <bits/stdc++.h>
using namespace std;
double comb(double n, double r) {
  double k = 1;
  if (r > n - r) {
    r = n - r;
  }
  for (double i = 0; i < r; i++) {
    k = k * (n - i);
    k = k / (i + 1);
  }
  return k;
}
double n, m, h, s1, sh, s = 0;
int main() {
  cin >> n >> m >> h;
  for (int i = 0; i < m; i++) {
    cin >> s1;
    if (i == h - 1) {
      sh = s1;
    }
    s = s + s1;
  }
  if (s < n) {
    cout << -1;
  } else if (s - sh < n - 1) {
    cout << 1;
  } else {
    cout << 1 - comb(s - sh, n - 1) / comb(s - 1, n - 1);
  }
}
