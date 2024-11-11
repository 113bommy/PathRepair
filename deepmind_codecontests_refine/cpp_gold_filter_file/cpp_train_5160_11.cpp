#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  cout << "? 1 2" << endl;
  long long x;
  cin >> x;
  cout << "? 2 3" << endl;
  long long y;
  cin >> y;
  cout << "? 1 3" << endl;
  long long z;
  cin >> z;
  long long a[n];
  a[0] = (x + z - y) / 2;
  a[1] = (x + y - z) / 2;
  a[2] = (y + z - x) / 2;
  for (long long i = 4; i <= n; i++) {
    cout << "? 1 " << i << "\n";
    cin >> x;
    a[i - 1] = x - a[0];
  }
  cout << "! ";
  for (long long i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
}
