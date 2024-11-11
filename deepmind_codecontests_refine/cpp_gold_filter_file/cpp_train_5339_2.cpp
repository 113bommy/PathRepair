#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    int a[n], count = 0, p = 1;
    for (int i = 0; i < n; i++) cin >> a[i];
    int x = 1, y = 0;
    for (int i = 1; i < n; i += p) {
      p = 1;
      for (int j = i + 1; j < n; j++) {
        if (a[j] > a[j - 1]) {
          p++;
        } else
          break;
      }
      y += p;
      x--;
      if (x == 0) {
        count++;
        x = y;
        y = 0;
      }
    }
    if (y != 0) count++;
    cout << count << endl;
  }
}
