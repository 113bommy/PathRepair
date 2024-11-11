#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i;
  cin >> t;
  long long int n, k;
  while (t--) {
    cin >> n >> k;
    vector<long long int> a(n);
    long long minb = 100000000;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      minb = min(minb, k + a[i]);
    }
    for (i = 0; i < n; i++) {
      if (abs(a[i] - minb) > k) {
        minb = -1;
        break;
      }
    }
    cout << minb << endl;
  }
  return 0;
}
