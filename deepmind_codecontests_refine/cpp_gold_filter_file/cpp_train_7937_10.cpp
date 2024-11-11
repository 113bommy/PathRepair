#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> v1(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      v1[i] = v[i];
    }
    sort(v1.begin(), v1.end());
    int d = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] != v1[i]) {
        d = 1;
      }
    }
    if (d == 0) {
      cout << 0 << endl;
      continue;
    }
    int i = 0, p = 0, q = 0;
    if (v1[i] != v[i]) {
      while (v1[i] != v[i] && i < n) {
        i++;
        p = 1;
      }
      while (v1[i] == v[i] && i < n) {
        i++;
        q = 1;
      }
      if (i == n) {
        cout << 1 << endl;
        continue;
      } else {
        cout << 2 << endl;
        continue;
      }
    } else {
      while (v1[i] == v[i] && i < n) {
        i++;
        q = 1;
      }
      while (v1[i] != v[i] && i < n) {
        i++;
        p = 1;
      }
      while (v1[i] == v[i] && i < n) {
        i++;
        q = 1;
      }
      if (i == n) {
        cout << 1 << endl;
        continue;
      } else {
        cout << 2 << endl;
        continue;
      }
    }
  }
}
