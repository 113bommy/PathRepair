#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0, flag = -1, i;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n > 2) {
    for (i = 1; i < n; i++) {
      if (a[i] - a[i - 1] != a[i + 1] - a[i]) {
        flag = 0;
        break;
      }
    }
  }
  if (flag == -1)
    sum = a[n - 1] + a[1] - a[0];
  else if (flag == 0)
    sum = a[n - 1];
  cout << sum;
  return 0;
}
