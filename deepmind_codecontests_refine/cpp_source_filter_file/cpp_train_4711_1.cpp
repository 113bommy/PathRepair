#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n], i, j;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    int min = abs(a[0] - a[1]), x;
    for (i = 0; i < n; i++) {
      x = abs(a[i] - a[i + 1]);
      if (min > x) min = x;
    }
    cout << min;
    cout << '\n';
  }
}
