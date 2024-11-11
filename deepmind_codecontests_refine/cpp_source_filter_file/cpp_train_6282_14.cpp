#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b) return gcd(a - b, b);
  return gcd(a, b - a);
}
int main() {
  int n, m, a[101], b[101];
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= m; i++) {
    cin >> b[i];
  }
  if (n == m) {
    int x = gcd(abs(a[0]), abs(b[0]));
    if (a[0] * b[0] < 0) {
      cout << "-";
    }
    cout << abs(a[0] / x) << "/" << abs(b[0] / x);
  } else if (n > m) {
    if (a[0] > 0) {
      cout << "Infinity";
    } else {
      cout << "-Infinity";
    }
  } else {
    cout << "0/1";
  }
  return 0;
}
