#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, mx = 2, j;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  if (n == 1)
    cout << "1";
  else if (n == 2)
    cout << "2";
  else {
    for (i = 2; i < n;) {
      int x = 0;
      for (j = i; j < n; j++) {
        if ((a[j] != (a[j - 1] + a[j - 2]))) break;
        x++;
      }
      i = ++j;
      mx = max(x + 2, mx);
    }
    cout << mx;
  }
  return 0;
}
