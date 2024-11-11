#include <bits/stdc++.h>
using namespace std;
int kol, a[2000], n, lrr[10], rrr[10];
int f(int x) {
  int i, j, g, l = 0;
  for (i = 1; i <= n; i++)
    if (a[i] != i) {
      l = 1;
      break;
    }
  if (l == 0) {
    kol = x - 1;
    return 1;
  }
  if (x > 3) return 0;
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      if (abs(a[i - 1] - a[j]) == 1) {
        reverse(a + i, a + j + 1);
        lrr[x] = i, rrr[x] = j;
        if (f(x + 1) == 1) return 1;
        reverse(a + i, a + j + 1);
      }
    }
  }
}
int main() {
  int i;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  f(1);
  cout << kol << '\n';
  for (i = kol; i >= 1; i--) cout << lrr[i] << ' ' << rrr[i] << '\n';
}
