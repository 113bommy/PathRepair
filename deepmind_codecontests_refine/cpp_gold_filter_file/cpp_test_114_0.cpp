#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long a[n], minn = 99999999;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (minn > a[i]) {
        minn = a[i];
      }
    }
    int req = n / 2, i = 0;
    while (i < n && req > 0) {
      if (a[i] != minn) {
        cout << a[i] << " " << minn << endl;
        req--;
      }
      i++;
    }
  }
  return 0;
}
