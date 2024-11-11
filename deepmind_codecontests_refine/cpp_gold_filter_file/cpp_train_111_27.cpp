#include <bits/stdc++.h>
using namespace std;
int main() {
  long long b = 0, c, d, n, i, s = 0, k, s1 = 0, j;
  cin >> n;
  int a[n + 7];
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    s = s + a[i];
    if (a[i] > b) {
      b = a[i];
    }
  }
  for (i = b; i <= 210; i++) {
    for (j = 1; j <= n; j++) {
      s1 = s1 + (i - a[j]);
    }
    if (s1 > s) {
      cout << i;
      return 0;
    }
    s1 = 0;
  }
  return 0;
}
