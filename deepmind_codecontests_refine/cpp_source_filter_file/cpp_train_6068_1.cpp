#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int x = 0;
    int val = v[n - 1];
    for (int i = 0; i < n; i++) {
      x = v[i] - v[i + 1];
      if (x < 0) {
        val += x;
      }
    }
    if (val >= 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
