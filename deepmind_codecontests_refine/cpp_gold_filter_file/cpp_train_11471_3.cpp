#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a = 0;
  cin >> t;
  while (t--) {
    vector<int> v;
    int n, k, r = 0, value = 0, z = 0;
    cin >> n;
    k = (4 * n);
    for (int i = 0; i <= k - 1; i++) {
      cin >> value;
      v.push_back(value);
    }
    for (int i = 0; i <= k - 1; i++) {
      a = count(v.begin(), v.end(), v[i]);
      if (a % 2 != 0) {
        cout << "NO" << endl;
        break;
      } else
        z++;
    }
    if (z == k) {
      sort(v.begin(), v.end());
      for (int i = 0; i < 2 * n; i++) {
        if (v[i] * v[k - 1 - i] == v[i + 1] * v[k - 2 - i]) {
          r++;
        }
      }
      if (r == (k / 2))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
