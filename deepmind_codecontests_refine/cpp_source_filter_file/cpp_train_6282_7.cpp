#include <bits/stdc++.h>
using namespace std;
int n, m, a[101], b[101];
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main() {
  scanf("%d%d", &n, &m);
  n++;
  m++;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
  if (n == m) {
    int k = gcd(max(a[1], b[1]), min(a[1], b[1]));
    if (b[1] / k > 0)
      printf("%d/%d", a[1] / k, b[1] / k);
    else
      printf("%d/%d", -a[1] / k, -b[1] / k);
  } else {
    if (m < n && a[1] * b[1] > 0)
      cout << "Infinity";
    else {
      if (m > n)
        cout << "0/1";
      else
        cout << "-Infinity";
    }
  }
}
