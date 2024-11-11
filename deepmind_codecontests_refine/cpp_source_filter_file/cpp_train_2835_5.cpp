#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    long long int i;
    for (i = 0; i < n; i++) cin >> a[i];
    bool flag = false;
    for (i = 0; i < n - 1; i++) {
      if ((a[i + 1] - a[i]) % 2 == 1) {
        flag = true;
        break;
      }
    }
    if (flag)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
