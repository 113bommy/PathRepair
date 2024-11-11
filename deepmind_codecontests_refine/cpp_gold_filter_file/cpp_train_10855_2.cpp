#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n + 1];
    int s = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      s += a[i];
    }
    if (s % n != 0)
      cout << -1 << endl;
    else {
      s = s / n;
      cout << 3 * n - 3 << endl;
      for (int i = 2; i <= n; i++) {
        if (a[i] % i == 0)
          cout << 1 << " " << i << " " << 0 << endl;
        else
          cout << 1 << " " << i << " " << i - (a[i] % i) << endl;
        cout << i << " " << 1 << " " << (a[i] + i - 1) / i << endl;
      }
      for (int i = 2; i <= n; i++) {
        cout << 1 << " " << i << " " << s << endl;
      }
    }
  }
}
