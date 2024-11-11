#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> t;
    v.push_back(t);
  }
  bool is = true;
  for (int i = 0; i < n; i++) {
    bool br = false;
    for (int j = 1000; j >= 1; j /= 10) {
      for (int k = (v[i] % (j * 10)) / j; k > 0; k--) {
        if (v[i] - k * j <= 2011 && v[i] - k * j >= 1000 &&
            (i == 0 || v[i - 1] <= v[i] - k * j)) {
          v[i] -= (k * j);
          br = true;
          break;
        }
      }
      if (br) break;
    }
    if (v[i] <= 2011 && v[i] >= 1000 && (i == 0 || v[i - 1] <= v[i])) continue;
    if (!br) {
      for (int j = 1; j <= 1000; j *= 10) {
        for (int k = 1; k <= (v[i] % (j * 10)) / j; k++) {
          if (v[i] + k * j <= 2011 && v[i] + k * j >= 1000 &&
              (i == 0 || v[i - 1] <= v[i] + k * j)) {
            v[i] += (k * j);
            br = true;
            break;
          }
        }
        if (br) break;
      }
    }
    if (!br) {
      is = false;
      break;
    }
  }
  if (!is) {
    cout << "No solution" << endl;
  } else {
    for (int i = 0; i < n; i++) cout << v[i] << endl;
  }
}
