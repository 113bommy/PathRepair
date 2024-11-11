#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, i, j, x, y, z, p, k, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long int b[n], a[2 * n];
    map<long int, long int> str;
    for (i = 0; i < 2 * n; i++) {
      cin >> a[i];
      str[a[i]]++;
    }
    k = -1;
    for (i = 0; i < 2 * n; i++) {
      if (str[a[i]] == 2) {
        k++;
        b[k] = a[i];
        str[a[i]]--;
      }
    }
    for (i = 0; i < k; i++) {
      cout << b[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
