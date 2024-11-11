#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int k;
    cin >> k;
    int j = 1;
    while (true) {
      if (k == 1) {
        cout << "1 1";
        break;
      }
      if (j * j < k && (j + 1) * (j + 1) >= k) {
        j++;
        int w = (j - 1) * (j - 1) + 1;
        int r = 1, c = j;
        for (int o = 1; o < j; o++)
          if (w < k) {
            w++;
            r++;
          }
        for (int o = 1; o < j; o++)
          if (w < k) {
            w++;
            c--;
          }
        cout << r << ' ' << c << endl;
        break;
      }
      j++;
    }
  }
  return 0;
}
