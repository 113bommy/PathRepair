#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    char g[n];
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> g[i] >> a[i] >> b[i];
    int yui = 0;
    for (int i = 0; i < 366; i++) {
      int m = 0, f = 0;
      for (int j = 0; j < n; j++) {
        if (a[j] <= i && b[j] >= i)
          if (g[j] == 'F')
            f++;
          else
            m++;
      }
      yui = max(yui, 2 * min(f, m));
    }
    cout << yui << endl;
  }
  return 0;
}
