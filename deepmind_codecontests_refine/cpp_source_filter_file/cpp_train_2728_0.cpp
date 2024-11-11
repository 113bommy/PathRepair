#include <bits/stdc++.h>
using namespace std;
int mod(int x) {
  if (x > 0) return x;
  return -x;
}
int main(void) {
  int a, j, f, i, t, n;
  cin >> t;
  for (i = 0; i < t; i++) {
    f = 0;
    cin >> n;
    vector<int> v(n);
    for (j = 0; j < n; j++) {
      cin >> v[j];
    }
    for (j = 0; j < n - 1 && f == 0; j++) {
      if (mod(v[j + 1] - v[j]) > 1) {
        cout << "YES" << endl;
        cout << j << " " << j + 1 << endl;
        f = 1;
      }
    }
    if (f == 0) cout << "NO" << endl;
    v.clear();
  }
  return 0;
}
