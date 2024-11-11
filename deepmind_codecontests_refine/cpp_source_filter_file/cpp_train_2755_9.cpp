#include <bits/stdc++.h>
using namespace std;
int i, n, mn, c[1001], t, mx, j;
int main() {
  cin >> n;
  int a[n], c[n - 1];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 1; i < n - 1; i++) {
    a[i] = a[i] * (-1);
    for (j = 1; j < n - 1; j++) {
      if (a[j] < 0) {
        mx = max(mx, a[j + 1] - a[j - 1]);
        j++;
      } else
        mx = max(mx, a[j] - a[j - 1]);
    }
    a[i] = a[i] * (-1);
    c[t] = mx;
    t++;
    mx = 0;
  }
  sort(c, c + t);
  cout << c[0];
}
