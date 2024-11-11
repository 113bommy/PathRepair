#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    int k;
    scanf("%lld%d", &n, &k);
    if (k > n || (n % 2 == 1 && k % 2 == 0)) {
      cout << "NO" << endl;
      continue;
    }
    if (n % 2 == k % 2) {
      cout << "YES" << endl;
      cout << n - (k - 1) << " ";
      for (int i = 0; i < n - (n - (k - 1)); i++) {
        cout << 1 << " ";
      }
    } else {
      if (n - (k - 1) * 2 <= 0) {
        cout << "NO" << endl;
        continue;
      }
      cout << "YES" << endl;
      cout << n - (k - 1) * 2 << " ";
      for (int i = 0; i < (n - (n - (k - 1) * 2)) / 2; i++) {
        cout << 2 << " ";
      }
    }
    cout << '\n';
  }
}
