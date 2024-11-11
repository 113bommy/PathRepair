#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[100005], b[100005], count, t, n, i, diff;
  cin >> t;
  while (t--) {
    count = 0;
    diff = 0;
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) cin >> b[i];
    for (i = 0; i < n; i++) {
      if (a[i] - b[i] != diff) {
        diff = a[i] - b[i];
        if (!diff) count++;
      }
      if (diff > 0) count += 5;
    }
    if (count > 1)
      cout << "NO";
    else
      cout << "YES";
    cout << endl;
  }
  return 0;
}
