#include <bits/stdc++.h>
using namespace std;
int fq[15000005];
int a[300005];
bool prime[15000005];
int m;
int gcd(int a, int b) {
  int c;
  while (b) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
int n, x;
int ggcd;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    ggcd = gcd(x, ggcd);
    a[i] = x;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = a[i] / ggcd;
    fq[a[i]]++;
  }
  m = 15000005;
  for (int i = 2; i + i < 15000005; i++) {
    if (!prime[i]) {
      int nr = fq[i];
      for (int j = i + i; j < 15000005; j += i) {
        nr += fq[j];
        prime[j] = 1;
      }
      m = min(m, n - nr);
    }
  }
  if (m < n) {
    cout << m << '\n';
  } else {
    cout << -1 << '\n';
  }
  return 0;
}
