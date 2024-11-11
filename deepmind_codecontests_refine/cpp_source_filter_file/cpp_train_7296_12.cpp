#include <bits/stdc++.h>
using namespace std;
int f[100], m, n;
int main() {
  cin >> m >> n;
  int x;
  for (int i = 0; i < n; i++) {
    cout << 1 << endl;
    cin >> f[i];
    if (f[i] == 0 || f[i] == 2) return 0;
  }
  int l = 1, r = m, mid;
  for (int i = 0; i <= 300; i++) {
    mid = (l + r) / 2;
    cout << mid << endl;
    cin >> x;
    if (x == 0 || x == 2) return 0;
    x = x * f[i % n];
    if (x == 1)
      l = mid;
    else
      r = mid;
  }
  return 0;
}
