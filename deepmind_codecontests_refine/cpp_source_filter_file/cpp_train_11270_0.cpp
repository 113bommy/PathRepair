#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, flag = 0;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i < n - 1; i++) {
      if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
        cout << "YES"
             << "\n";
        cout << i << " " << i + 1 << " " << i + 2;
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
