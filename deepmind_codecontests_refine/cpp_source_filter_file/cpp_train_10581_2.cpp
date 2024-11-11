#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a[i] = x;
    b[i] = y;
  }
  float min = 500.0;
  float c;
  for (int i = 0; i < n; i++) {
    c = float(a[i] * m) / float(b[i]);
    if (c < min) min = c;
  }
  cout << setprecision(9) << min;
  return 0;
}
