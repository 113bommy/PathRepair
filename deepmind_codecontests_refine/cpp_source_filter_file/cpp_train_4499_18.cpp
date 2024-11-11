#include <bits/stdc++.h>
const int N = 100;
using namespace std;
int i, t, d, a[N];
long long fi[N], n, kq, f[N];
void khoitao() {
  fi[1] = 1;
  fi[2] = 2;
  for (i = 3; i <= 90; i++) fi[i] = fi[i - 1] + fi[i - 2];
}
long long tinh(int d, int c) {
  if (d == 0) return (c + 1) / 2;
  if ((c - d) % 2 == 0) return (c - d) / 2 + 1;
  return (c - d + 1) / 2;
}
void vao() {
  khoitao();
  cin >> t;
}
void xuly() {
  while (t--) {
    cin >> n;
    i = 90;
    d = 0;
    while (n != 0) {
      while (fi[i] > n) i--;
      a[++d] = i;
      n -= fi[i];
    }
    a[++d] = 0;
    f[1] = tinh(a[2], a[1]);
    if (d > 2) {
      f[2] = f[1] * tinh(a[3], a[2]);
      if ((a[1] - a[2]) % 2 == 0) f[2]--;
      for (i = 3; i <= d - 1; i++)
        if ((a[i - 1] - a[i]) % 2 == 0)
          f[i] = (f[i - 1] - f[i - 2]) * tinh(a[i + 1], a[i]) +
                 f[i - 2] * (tinh(a[i + 1], a[i]) - 1);
        else
          f[i] = f[i - 1] * tinh(a[i + 1], a[i]);
    }
    cout << f[d - 1];
  }
}
void ra() {}
int main() {
  vao();
  xuly();
  ra();
  return 0;
}
