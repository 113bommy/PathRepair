#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    if (i != (n - 1) && i != 0 && (abs(a[i] - a[i - 1]) < abs(a[i] - a[i + 1])))
      cout << abs(a[i] - a[i - 1]) << " ";
    if (i != (n - 1) && i != 0 &&
        (abs(a[i] - a[i - 1]) >= abs(a[i] - a[i + 1])))
      cout << abs(a[i] - a[i + 1]) << " ";
    if (i == 0) cout << abs(a[i] - a[i + 1]) << " ";
    if (i == n - 1) cout << abs(a[i] - a[i - 1]) << " ";
    if (abs(a[i] - a[0]) > abs(a[i] - a[n - 1]))
      cout << abs(a[i] - a[0]) << endl;
    if (abs(a[i] - a[0]) <= abs(a[i] - a[n - 1]))
      cout << abs(a[i] - a[n - 1]) << endl;
  }
}
