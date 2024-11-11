#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int j = 0; j < t; ++j) {
    string a, b;
    cin >> a >> b;
    vector<char> v;
    if (a < b) {
      cout << a << endl;
      continue;
    }
    for (int i = 0; i < a.size(); ++i) {
      v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    int f = 0;
    for (int i = 0; i < v.size(); ++i) {
      if (a[i] == v[i]) continue;
      char curr = a[i];
      int idx = -1;
      for (int k = i + 1; k < a.size(); k++) {
        if (curr >= a[k]) {
          curr = a[k];
          idx = k;
        }
      }
      swap(a[i], a[idx]);
      if (a < b) {
        cout << a << endl;
        f = 1;
      }
      break;
    }
    if (f) continue;
    if (a >= b) cout << "---" << endl;
  }
  return 0;
}
