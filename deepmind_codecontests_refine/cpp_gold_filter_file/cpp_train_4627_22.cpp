#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b;
  cin >> n >> b;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int mn = a[0];
  int res = b;
  for (int i = 1; i < n; i++) {
    if (a[i] < mn)
      mn = a[i];
    else if (mn < a[i]) {
      int sum = b % mn;
      int r = b / mn;
      sum += r * a[i];
      res = max(res, sum);
    }
  }
  cout << res << endl;
  return 0;
}
