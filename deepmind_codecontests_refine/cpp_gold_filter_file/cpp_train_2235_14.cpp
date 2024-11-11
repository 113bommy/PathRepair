#include <bits/stdc++.h>
using namespace std;
int a, b;
int A[10], B[10];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b;
  int base = 0;
  int p = 1;
  for (int i = 0; i < 10; i++) {
    A[i] = (a / p) % 10;
    B[i] = (b / p) % 10;
    base = max(base, A[i]);
    base = max(base, B[i]);
    p *= 10;
  }
  base++;
  int g = 1, s = 0;
  for (int i = 0; i < 10; i++) {
    s += (A[i] + B[i]) * g;
    g *= base;
  }
  int d = 1;
  while (s >= base) {
    s /= base;
    d++;
  }
  cout << d << "\n";
  return 0;
}
