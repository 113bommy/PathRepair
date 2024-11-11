#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s1 = 0, s2 = 0, s = 0;
  cin >> n >> m;
  int a[m], b[m];
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  for (int i = 0; i < n; i++) {
    sort(a, a + m);
    s1 += a[m - 1];
    a[m - 1] -= 1;
  }
  sort(b, b + m);
  for (int i = 0; i < m; i++) {
    if (b[i] <= (n - s)) {
      s += b[i];
      s2 += (b[i] * (b[i] + 1)) / 2;
    } else {
      for (int j = 0; (n - s - j) >= 0; j++) {
        s2 += b[i];
        b[i] -= 1;
      }
      break;
    }
  }
  cout << s1 << " " << s2;
}
