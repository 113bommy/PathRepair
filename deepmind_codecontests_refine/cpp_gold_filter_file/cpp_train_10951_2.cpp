#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, ans = 1, f = 0, k = 0;
    cin >> n;
    int* a = new int[n];
    int* b = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) {
        ans = 0;
        break;
      } else if (f == 1 && b[i] == a[i])
        f = 2;
      else if (f == 2 && b[i] != a[i]) {
        ans = 0;
        break;
      } else if (b[i] != a[i]) {
        if (f && b[i] - a[i] != k) {
          ans = 0;
          break;
        }
        k = b[i] - a[i];
        f = 1;
      }
    }
    if (ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
