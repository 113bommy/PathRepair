#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    long long int sum = a[0];
    long long int last_added = a[0];
    for (int i = 1; i < n; i++) {
      if (a[i] * a[i - 1] > 0) {
        if (a[i] > a[i - 1]) {
          sum = sum + a[i] - last_added;
          last_added = a[i];
        }
      } else {
        sum += a[i];
        last_added = a[i];
      }
    }
    cout << sum << endl;
  }
  return 0;
}
