#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[55];
  int sum;
  int t;
  cin >> t;
  int n;
  while (t--) {
    cin >> n;
    sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) sum += a[i];
    if (sum == 0) {
      cout << "NO" << endl;
      continue;
    } else if (sum > 0) {
      cout << "YES" << endl;
      int pos = 0;
      while (a[pos] <= 0) pos++;
      cout << a[pos];
      for (int i = 0; i < n; i++)
        if (a[i] > 0 && i != pos) cout << ' ' << a[i];
      for (int i = 0; i < n; i++)
        if (a[i] <= 0) cout << ' ' << a[i];
      cout << endl;
    } else {
      cout << "YES" << endl;
      int pos = 0;
      while (a[pos] >= 0) pos++;
      cout << a[pos];
      for (int i = 0; i < n; i++)
        if (a[i] < 0 && i != pos) cout << ' ' << a[i];
      for (int i = 0; i < n; i++)
        if (a[i] >= 0) cout << ' ' << a[i];
      cout << endl;
    }
  }
  return 0;
}
