#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1], sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum != 0) {
    cout << "YES\n"
         << "1\n"
         << "1 " << n << endl;
    return 0;
  } else {
    int s = 0;
    for (int i = 1; i <= n; i++) {
      s += a[i];
      if (s != 0) {
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << "1"
             << " " << i << "\n"
             << i << " " << n << endl;
        return 0;
      }
    }
    cout << "NO" << endl;
  }
  return 0;
}
