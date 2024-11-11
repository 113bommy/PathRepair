#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v = {};
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    v.push_back(k);
  }
  int m;
  cin >> m;
  for (int j = 0; j < m; j++) {
    int r, b;
    cin >> r >> b;
    if (r == 1) {
      v[r] = v[r] + v[r - 1] - b;
      v[r - 1] = 0;
    } else if (r == m) {
      v[r - 2] = v[r - 2] + b - 1;
      v[r - 1] = 0;
    } else {
      v[r - 2] = v[r - 2] + b - 1;
      v[r] = v[r] + v[r - 1] - b;
      v[r - 1] = 0;
    }
  }
  for (int k : v) {
    cout << k << endl;
  }
  return 0;
}
