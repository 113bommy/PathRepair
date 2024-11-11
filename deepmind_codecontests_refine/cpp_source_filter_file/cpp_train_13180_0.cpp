#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, a[110] = {0}, b[110], c[110], k = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> b[i] >> c[i];
  for (int i = 1; i <= n; i++) {
    if (b[i] == 0) {
      a[k++] = i;
      int z = i;
      while (c[z] != 0)
        for (int j = 1; j <= n; j++)
          if (b[j] == z) {
            a[k++] = j;
            z = j;
            break;
          }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; i <= n; j++)
      if (a[j] == i && j == 1) {
        cout << a[n] << ' ' << a[j + 1];
        break;
      } else if (a[j] == i && j == n) {
        cout << a[j - 1] << ' ' << a[1];
        break;
      } else if (a[j] == i) {
        cout << a[j - 1] << ' ' << a[j + 1];
        break;
      }
    cout << endl;
  }
  return 0;
}
