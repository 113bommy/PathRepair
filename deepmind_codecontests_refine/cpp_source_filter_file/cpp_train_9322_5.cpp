#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x[n + 2];
  x[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  x[n + 2] = 1000000001;
  sort(x, x + n + 2);
  int q;
  cin >> q;
  int m[q];
  for (int i = 0; i <= q - 1; i++) {
    cin >> m[i];
    int l = 0;
    int r = n + 1;
    while (r - l > 1) {
      int mi = (r + l) / 2;
      if (m[i] >= x[mi]) {
        l = mi;
      } else {
        r = mi;
      }
    }
    cout << l << "\n";
  }
}
