#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, min;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    min = a[1] - a[0];
    for (int j = 1; j < n - 1; j++) {
      if (a[j + 1] - a[j] < min) min = a[j + 1] - a[j];
    }
    cout << min;
  }
}
