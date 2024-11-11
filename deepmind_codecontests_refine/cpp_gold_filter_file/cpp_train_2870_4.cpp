#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int min = n;
  while (m--) {
    int x, y;
    cin >> x >> y;
    if (y - x + 1 < min) {
      min = y - x + 1;
    }
  }
  int z = 0, a[n];
  for (__typeof((n)) i = (0); i < (n); i += 1) {
    a[i] = z % min;
    z += 1;
  }
  cout << min << "\n";
  for (__typeof((n)) i = (0); i < (n); i += 1) {
    cout << a[i] << " ";
  }
}
