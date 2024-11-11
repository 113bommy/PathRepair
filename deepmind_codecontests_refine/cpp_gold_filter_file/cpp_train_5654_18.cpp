#include <bits/stdc++.h>
using namespace std;
long n, a, b, ma;
long aa[1000];
long i, j;
int main() {
  cin >> n >> a >> b;
  if (n == 1 && a == 0 && b == 0) {
    cout << 1 << endl;
    return 0;
  }
  if ((a + b >= n) || ((a > (n - 2)) && (b == 0))) {
    cout << -1 << endl;
    return 0;
  }
  if (b == 0) {
    if (a == 0) {
      for (i = 1; i <= n; i++) cout << 1 << " ";
      cout << endl;
      return 0;
    }
    if (n == 2) {
      cout << -1 << endl;
      return 0;
    }
    cout << 1 << " " << 1 << " ";
    for (i = 1; i <= a; i++) cout << i + 1 << " ";
    for (i = 1; i <= n - a - 2; i++) cout << 1 << " ";
    cout << endl;
    return 0;
  }
  aa[1] = 2;
  for (i = 2; i <= 1 + b; i++) {
    ma = 0;
    for (j = 1; j <= i - 1; j++) ma = ma + aa[j];
    aa[i] = ma + 1;
  }
  for (i = 2 + b; i <= 1 + b + a; i++) aa[i] = aa[i - 1] + 1;
  for (i = a + 1 + b + 1; i <= n; i++) aa[i] = aa[a + 1 + b] - 1;
  for (i = 1; i <= n; i++) cout << aa[i] << " ";
  cout << endl;
}
