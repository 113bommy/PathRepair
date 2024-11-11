#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long t = 1, ca = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if (n == 1) {
      cout << "1 1\n";
      cout << -a[1] << endl;
      cout << "1 1\n0\n1 1\n0\n";
    } else if (n == 2) {
      cout << "1 1\n";
      cout << -a[1] << endl;
      cout << "2 2\n";
      cout << -a[2] << endl;
      cout << "1 1\n0\n";
    } else if (n == 3) {
      cout << "1 1\n";
      cout << -a[1] << endl;
      cout << "2 2\n";
      cout << -a[2] << endl;
      cout << "3 3\n";
      cout << -a[3] << endl;
    } else {
      long long x = n, y = n - 1;
      long long b[n + 1];
      cout << 1 << " " << x << endl;
      for (int i = 1; i < n; i++) {
        long long z = a[i] % y;
        z = y - z;
        z = z * x;
        cout << z << " ";
        a[i] = z + a[i];
      }
      cout << 0 << endl;
      cout << 1 << " " << y << endl;
      for (int i = 1; i < n; i++) cout << -a[i] << " ";
      cout << endl;
      cout << n << " " << n << endl;
      cout << -a[n] << endl;
    }
  }
}
