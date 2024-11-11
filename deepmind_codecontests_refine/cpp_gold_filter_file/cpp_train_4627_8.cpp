#include <bits/stdc++.h>
using namespace std;
int main() {
  int b, c, d, e, n, i, j, s = 0, m, k;
  cin >> n >> b;
  int a[n];
  s = b;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      k = b % a[i] + a[j] * (b / a[i]);
      s = max(s, k);
    }
  }
  cout << s;
}
