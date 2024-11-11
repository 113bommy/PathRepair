#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, r, a, min = 1000, max = 0;
  cin >> n >> m >> r;
  for (int c = 0; c < n; c++) {
    cin >> a;
    if (a < min) min = a;
  }
  for (int c = 0; c < m; c++) {
    cin >> a;
    if (a > max) max = a;
  }
  if (max <= min)
    cout << r;
  else
    cout << (r / min) * max + r % min;
}
