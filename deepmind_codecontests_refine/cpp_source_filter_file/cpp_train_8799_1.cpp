#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  int Tong = 0;
  int Mang[100] = {0};
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) cin >> Mang[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int x, vt;
      cin >> x;
      for (int t = 0; t < k; t++)
        if (Mang[t] == x) {
          vt = t;
          break;
        }
      for (int t = vt; t > 0; t--) Mang[t] = Mang[t - 1];
      Mang[0] = x;
      Tong += x + 1;
    }
  cout << Tong;
  return 0;
}
