#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, l;
  cin >> n >> d >> l;
  int a[n];
  int omin = (n + 1) / 2, omax = (n + 1) / 2 * l;
  int emin = n / 2, emax = (n) / 2 * l;
  if (d > 0) {
    if (omax - emin < d) {
      cout << -1 << endl;
      return 0;
    }
  } else {
    if (omin - emax > d) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) a[i] = 1;
  int se = 0, so = 0;
  for (int i = 0; i < n; i++)
    if (i & 1)
      se += a[i];
    else
      so += a[i];
  if (d < 0) {
    for (int i = 0; i < n; i++)
      if (i & 1) a[i] = a[i] * l, se += l - 1;
  }
  while (so - se < d) {
    for (int i = 0; i < n; i++)
      if (i % 2 == 0 && so - se < d) a[i] += 1, so++;
  }
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
}
