#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, q, ans_n = 0, ans_m = 0, y = 0;
  cin >> n >> m;
  string a[n], b[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  cin >> y;
  for (int i = 0; i < y; i++) {
    cin >> q;
    if (n >= q) {
      ans_n = q;
    } else {
      ans_n = q - ((q / n) * n);
    }
    if (m >= q) {
      ans_m = q;
    } else {
      ans_m = q - ((q / m) * m);
    }
    if (ans_n == 0) {
      ans_n = n;
    }
    if (ans_m == 0) {
      ans_m = n;
    }
    cout << a[ans_n - 1] << b[ans_m - 1] << endl;
  }
  return 0;
}
