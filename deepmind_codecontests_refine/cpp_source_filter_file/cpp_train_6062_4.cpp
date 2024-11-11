#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int i, s, g, n, m;
    cin >> n >> m;
    long long int a[n];
    s = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      s = s + a[i];
    }
    sort(a, a + n);
    if (s < m) {
      cout << a[n - 1] << endl;
    } else {
      cout << m << endl;
    }
  }
  return 0;
}
