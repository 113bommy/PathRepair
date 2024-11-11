#include <bits/stdc++.h>
using namespace std;
long long n, i, a[10000000], g[10000000], ap, gp, flag;
char t[10000000];
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i] >> g[i];
  }
  ap = 0;
  gp = 0;
  flag = 1;
  for (i = 1; i <= n; i++) {
    if (abs((a[i] + ap) - gp) <= 500) {
      t[i] = 'A';
      ap += a[i];
    } else if (abs((g[i] + gp) - ap) <= 500) {
      t[i] = 'G';
      gp += g[i];
    } else {
      flag = 0;
      break;
    }
  }
  if (!flag) {
    cout << "-1";
  } else {
    for (i = 1; i <= n; i++) {
      cout << t[i] << "\n";
    }
  }
  return 0;
}
