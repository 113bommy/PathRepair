#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (k % 2 == 0)
      k = 2;
    else
      k = 1;
    while (k--) {
      long long m = -10000000000;
      for (int i = 0; i < n; i++) {
        m = max(m, a[i]);
      }
      for (int i = 0; i < n; i++) {
        a[i] = m - a[i];
      }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}
