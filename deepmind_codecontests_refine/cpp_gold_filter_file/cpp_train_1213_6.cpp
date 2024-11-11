#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j = 0, k = 0, l, m, a, b, n;
  double c = 0;
  cin >> n >> a >> b;
  long long s[n], ar[n];
  for (i = 0; i < n; i++) {
    cin >> s[i];
    ar[i] = s[i];
    c = c + s[i];
  }
  if ((a * s[0]) / c >= b) {
    printf("0\n");
  } else {
    sort(ar, ar + n);
    for (i = n - 1; i >= 0; i--) {
      if (ar[i] != s[0] || k == 1) {
        c = c - ar[i];
        j++;
      } else
        k = 1;
      if ((a * s[0]) / c >= b) {
        cout << j << endl;
        break;
      }
    }
  }
}
