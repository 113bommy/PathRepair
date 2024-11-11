#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long int x, y, z;
    x = a[0];
    y = a[1];
    z = a[n - 1];
    if (x + y < z) {
      cout << "1 2 " << n << "\n";
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
