#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, j, c = 0;
    vector<int> v;
    cin >> n;
    for (i = 0; i < n; i++) {
      int k;
      cin >> k;
      v.push_back(k);
    }
    sort(v.begin(), v.end());
    for (i = 1; i < n; i++) {
      if (v[i] - v[i - 1] == 1) {
        c++;
      }
    }
    if (c >= 1) {
      cout << 2 << endl;
    } else {
      cout << 1 << endl;
    }
  }
  return 0;
}
