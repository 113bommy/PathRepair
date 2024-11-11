#include <bits/stdc++.h>
using namespace std;
long long a[1000], b[1000];
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    long long m = 0;
    for (int l = 0; l < n; ++l) {
      long long fa = a[l], fb = a[l];
      m = max(m, fa + fb);
      for (int r = l + 1; r < n; ++r) {
        fa |= a[r];
        fb |= b[r];
        m = max(m, fa + fb);
      }
    }
    cout << m << endl;
  }
  return 0;
}
