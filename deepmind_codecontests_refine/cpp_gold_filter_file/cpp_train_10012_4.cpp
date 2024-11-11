#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    int i, j;
    for (i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (j = n - 2; j >= 1; j--) {
      if (a[n - 2] >= j + 1) break;
    }
    cout << j << endl;
  }
  return 0;
}
