#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[105];
  while (cin >> n) {
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        for (int k = j; k < n; k++)
          if (a[k] > a[k + 1]) {
            swap(a[k], a[k + 1]);
            cout << k << ' ' << k + 1 << endl;
          }
      }
    }
  }
}
