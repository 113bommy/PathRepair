#include <bits/stdc++.h>
using namespace std;
int n, t, a[4], u;
int main() {
  cin >> t;
  while (t--) {
    cin >> a[1] >> a[2] >> a[3];
    sort(a + 1, a + 4);
    u = sqrt(a[1] * a[1] + (a[3] * a[3] - a[2] * a[2]));
    cout << u + 1 << "\n";
  }
}
