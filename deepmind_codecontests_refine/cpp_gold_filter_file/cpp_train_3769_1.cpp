#include <bits/stdc++.h>
using namespace std;
int main() {
  long q, i, j;
  double t, n[100], res[100], a[100], s;
  cin >> q;
  for (i = 0; i < q; i++) {
    cin >> n[i];
    s = 0;
    for (j = 0; j < n[i]; j++) {
      cin >> a[j];
      s += a[j];
    }
    t = s / n[i];
    res[i] = ceil(t);
  }
  for (i = 0; i < q; i++) {
    cout << long(res[i]) << "\n";
  }
  return 0;
}
