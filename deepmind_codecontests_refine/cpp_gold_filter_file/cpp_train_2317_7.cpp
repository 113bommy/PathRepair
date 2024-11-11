#include <bits/stdc++.h>
using namespace std;
int main() {
  long i, j, k, t, n, p, q, l;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> n;
    p = 0;
    vector<int> a, b;
    q = 0;
    for (j = 0; j < 2 * n; j++) {
      cin >> k;
      if (k % 2 == 0) {
        a.push_back(j + 1);
      } else {
        b.push_back(j + 1);
      }
    }
    l = 0;
    for (j = 0; j + 1 < a.size() && l < n - 1; j += 2) {
      cout << a[j] << " " << a[j + 1] << endl;
      l++;
    }
    for (j = 0; j + 1 < b.size() && l < n - 1; j += 2) {
      cout << b[j] << " " << b[j + 1] << endl;
      l++;
    }
  }
}
