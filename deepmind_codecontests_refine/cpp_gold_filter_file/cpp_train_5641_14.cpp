#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
int main() {
  int t, tmp = 0;
  cin >> t;
  int b[t], p[t], l[t], h[t], c[t];
  for (int i = 0; i < t; i++) {
    cin >> b[i] >> p[i] >> l[i] >> h[i] >> c[i];
  }
  for (int i = 0; i < t; i++) {
    int x = 0;
    if (max(h[i], c[i]) == h[i]) {
      if (b[i] <= 1) {
        cout << 0 << endl;
        continue;
      }
      b[i] = b[i] / 2;
      if (b[i] >= p[i]) {
        x += p[i] * h[i];
        b[i] -= p[i];
        if (b[i] >= l[i]) {
          x += l[i] * c[i];
        } else {
          x += b[i] * c[i];
        }
      } else {
        x += b[i] * h[i];
      }
    } else {
      if (b[i] <= 1) {
        cout << 0 << endl;
        continue;
      }
      b[i] = b[i] / 2;
      if (b[i] >= l[i]) {
        x += l[i] * c[i];
        b[i] -= l[i];
        if (b[i] >= p[i]) {
          x += p[i] * h[i];
        } else {
          x += b[i] * h[i];
        }
      } else {
        x += b[i] * c[i];
      }
    }
    cout << x << endl;
  }
}
