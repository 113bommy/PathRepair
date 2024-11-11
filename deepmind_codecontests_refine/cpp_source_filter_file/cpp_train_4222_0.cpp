#include <bits/stdc++.h>
using namespace std;
int c[1000001];
int b[1000001];
int main() {
  int n, i, l, r, m, kq = 0, a;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    cin >> a;
    c[a] = i;
    b[i] = 0;
  }
  cin >> a;
  b[1] = c[a];
  for (i = 2; i <= n; i++) {
    cin >> a;
    a = c[a];
    l = 1;
    r = i;
    while (l < r) {
      m = (l + r) / 2;
      if (b[m] > a)
        l = m + 1;
      else
        r = m;
    }
    b[r] = a;
    if (kq < r) kq = r;
  }
  cout << kq;
  return 0;
}
