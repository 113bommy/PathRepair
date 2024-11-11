#include <bits/stdc++.h>
using namespace std;
int n, a[100000 + 7], aa[100000 + 7];
int main(int argc, char **argv) {
  int n;
  cin >> n;
  a[0] = aa[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    aa[i] = a[i];
  }
  sort(aa, aa + n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    aa[i] += aa[i - 1];
  }
  int m, ty, l, r;
  cin >> m;
  while (m--) {
    cin >> ty >> l >> r;
    if (ty == 1) {
      cout << a[r] - a[l - 1] << endl;
    } else {
      cout << aa[r] - aa[l - 1] << endl;
    }
  }
  return 0;
}
