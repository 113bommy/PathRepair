#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c1[5010], a[5010], b[5010], c2[5010], c3[5010];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "?"
         << " " << 0 << " " << i << endl;
    cin >> c1[i];
  }
  for (int i = 0; i < n; i++) {
    cout << "?"
         << " " << i << " " << 0 << endl;
    cin >> c2[i];
  }
  int S = 0;
  bool x = 0;
  for (int i = 0; i < n; i++) {
    bool k = 0;
    a[0] = i;
    for (int m = 0; m < n; m++) {
      b[m] = c1[m] ^ i;
      if (b[m] >= n) {
        k = 1;
        break;
      }
    }
    for (int m = 1; m < n; m++) {
      a[m] = c2[m] ^ b[0];
      if (a[m] >= n) {
        k = 1;
        break;
      }
    }
    if (!k) {
      bool p = 0;
      for (int i = 0; i < n; i++) {
        if (a[b[i]] != i) {
          p = 1;
          break;
        }
      }
      if (!p) {
        S++;
        if (!x) {
          for (int i = 0; i < n; i++) c3[i] = a[i];
          x = 1;
        }
      }
    }
  }
  cout << "!" << endl;
  cout << S << endl;
  for (int i = 0; i < n; i++) cout << c2[i] << " ";
  cout << endl;
}
