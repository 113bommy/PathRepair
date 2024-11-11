#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p;
  while (cin >> n >> p) {
    int ans = -1;
    for (int i = 1; i <= 31; i++) {
      int x = n - p * i;
      if (x <= 0) continue;
      int k = 0;
      for (int j = 0; j < 32; j++) {
        if (x & (1 << j)) k++;
      }
      if (k <= i) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
