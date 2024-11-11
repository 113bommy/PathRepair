#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s, f, t, j;
  cin >> n >> m;
  int st[n];
  for (int i = 0; i < n; i++) {
    cin >> s >> f >> t;
    j = t / (2 * (m - 1));
    if (f - s > 0) {
      if (t > 2 * (m - 1) * j + s - 1) {
        st[i] = 2 * (m - 1) * (j + 1) + s - 1 + (f - s);
      } else {
        st[i] = 2 * (m - 1) * j + s - 1 + (f - s);
      }
    } else if (f - s < 0) {
      if (t > 2 * (m - 1) * j + 3 + m - s) {
        st[i] = 2 * (m - 1) * (j + 1) + (m - 1) + (m - s) + (s - f);
      } else {
        st[i] = 2 * (m - 1) * (j) + (m - 1) + (m - s) + (s - f);
      }
    } else
      st[i] = t;
    cout << st[i] << endl;
  }
  return 0;
}
