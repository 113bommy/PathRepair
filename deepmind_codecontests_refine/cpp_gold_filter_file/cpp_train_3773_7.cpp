#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int t, n, a[1000000], i, j, b = 0, c = 0, e, f, g, h, m[1000000];
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> n;
    h = n;
    for (j = 1; j <= n; j++) {
      cin >> a[j];
    }
    sort(a + 1, a + n + 1);
    for (j = 1; j <= n; j++) {
      if (b == 0) {
        m[j] = a[j - c];
        b = 1;
      } else {
        m[j] = a[n - c];
        b = 0;
        c++;
      }
    }
    for (j = n; j >= 1; j--) {
      cout << m[j] << " ";
    }
    cout << endl;
    b = 0;
    c = 0;
  }
}
