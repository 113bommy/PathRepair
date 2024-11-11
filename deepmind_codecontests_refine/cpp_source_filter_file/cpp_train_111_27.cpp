#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, max, l = 0, t = 0, j;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0)
      max = a[i];
    else {
      if (a[i] > max) max = a[i];
    }
  }
  for (i = max; i < 500; i++) {
    l = 0;
    t = 0;
    for (j = 0; j < n; j++) {
      l = l + a[j];
      t = t + i - a[j];
    }
    if (t >= l) {
      cout << i;
      break;
    }
  }
  return 0;
}
