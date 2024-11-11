#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, m, n, t;
  cin >> t;
  int a[t + 5];
  for (i = 0; i < t; i++) {
    cin >> a[i];
  }
  int cnt = 0, mx = 0;
  for (i = 1; i < t; i++) {
    if (a[i] == 1) {
      cnt++;
      mx = max(mx, cnt);
    } else
      cnt = 0;
  }
  if (a[t - 1] == 1) {
    i = 0;
    while (a[i] == 1) {
      cnt++;
      i++;
    }
  }
  mx = max(mx, cnt);
  cout << mx << endl;
  return 0;
}
