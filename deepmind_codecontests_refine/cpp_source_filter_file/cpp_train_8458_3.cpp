#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, temp, i, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int a[2 * n], b[n];
    for (i = 0; i < n; i++) {
      cin >> b[0];
    }
    for (i = 0; i < 2 * n; i++) {
      cin >> a[i];
      temp = a[i];
      temp--;
      b[temp] = b[temp] + 1;
      if (b[temp] == 1) {
        cout << a[i] << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
