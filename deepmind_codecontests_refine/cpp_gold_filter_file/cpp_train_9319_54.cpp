#include <bits/stdc++.h>
int a[1000] = {0};
int b[1000] = {0};
using namespace std;
int main() {
  int D = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int l = 0; l < n; l++) {
    for (int r = l; r < n; r++) {
      int resa;
      int resb;
      int R = 0;
      for (int y = l; y <= r; y++) {
        if (y == l) {
          resa = a[l];
          resb = b[l];
        } else {
          resa = resa | a[y];
          resb = resb | b[y];
        }
      }
      R = resa + resb;
      if (R > D) {
        D = R;
      }
    }
  }
  cout << D;
}
