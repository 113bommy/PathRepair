#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int f = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
      if (a[i + 1] - a[i] >= 2) {
        cout << "yes" << endl;
        cout << i << " " << i + 1 << endl;
        f = 1;
        break;
      }
    }
    if (f == 0) cout << "no" << endl;
  }
  return 0;
}
