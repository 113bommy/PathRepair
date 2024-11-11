#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int p[n], a[n], i;
    for (i = 0; i < n; i++) cin >> p[i];
    for (i = 1; i <= n; i++) {
      int m = 1;
      if (i == p[i - 1])
        a[i - 1] = 1;
      else {
        int x = i;
        while (i != p[x - 1]) {
          x = p[x - 1];
          m++;
        }
        a[i - 1] = m;
      }
    }
    for (i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
  }
}
