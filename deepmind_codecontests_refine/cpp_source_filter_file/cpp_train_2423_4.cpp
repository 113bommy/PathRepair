#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int a[n], i;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 1; i < n; i += 2) {
      cout << "-" << a[i] << " " << a[i - 1] << " ";
    }
    cout << "\n";
  }
}
