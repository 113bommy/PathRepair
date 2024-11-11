#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, x, count = 0, sum = 0;
    cin >> n >> x;
    long long int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum = sum + a[i];
    }
    sort(a, a + n);
    int k = n, m;
    for (int i = 0; i < n; i++) {
      if (sum / k < x) {
        m = 1;
        sum = sum - a[i];
        k--;
      } else {
        m = 0;
        cout << k << endl;
        break;
      }
    }
    if (m) cout << 0 << endl;
  }
}
