#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (!k) {
    cout << "NO" << endl;
    return 0;
  }
  int x, y, flag = 0;
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    if (x <= 5 || y <= 5 || (n - x) <= 4 || (m - y) <= 4) flag = 1;
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
