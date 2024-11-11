#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v, v1;
  int a, b, c, d, e, f, g, h, i, j, k, l;
  cin >> a;
  for (i = 0; i < a; i++) {
    v.clear();
    v1.clear();
    cin >> c >> d >> b;
    map<int, int> m;
    for (j = 0; j < b; j++) {
      cin >> e;
      m[e]++;
      v.push_back(e);
    }
    f = 0;
    g = -1;
    h = -1;
    int min1 = INT_MAX;
    for (j = 0; j < v.size(); j++) {
      for (k = d; k < c; k++) {
        if (!m.count(k)) {
          min1 = min(k - d, min1);
          break;
        }
      }
      for (k = d; k >= 1; k--) {
        if (!m.count(k)) {
          min1 = min(d - k, min1);
          break;
        }
      }
    }
    cout << min1 << endl;
  }
}
