#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a[100010];
  cin >> n >> k;
  k--;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int e = -1;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] != a[n - 1]) {
      e = i;
      break;
    }
  }
  if (k <= e && a[0] != a[n - 1]) {
    cout << -1 << endl;
    return 0;
  }
  cout << e + 1 << endl;
  return 0;
}
