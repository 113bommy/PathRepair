#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    if (n == 1) {
      if (m == 1)
        cout << "1\n";
      else if (m == 2)
        cout << "3 4\n";
      else {
        cout << m - 2 << ' ';
        for (long long i = 1; i < m; i++) cout << "2 ";
        cout << '\n';
      }
    } else if (m == 1) {
      if (n == 2)
        cout << "3\n4\n";
      else {
        cout << n - 2 << ' ';
        for (long long i = 1; i < n; i++) cout << "2 ";
        cout << '\n';
      }
    } else if (n == 2) {
      if (m == 2)
        cout << "3 4\n4 3\n";
      else {
        cout << 3 * (m - 2) << ' ';
        for (long long i = 1; i < m; i++) cout << "6 ";
        cout << '\n';
        cout << 4 * (m - 2) << ' ';
        for (long long i = 1; i < m; i++) cout << "8 ";
        cout << '\n';
      }
    } else if (m == 2) {
      cout << 3 * (n - 2) << ' ' << 4 * (n - 2) << '\n';
      for (long long i = 1; i < n; i++) cout << "6 8\n";
    } else {
      cout << (n - 2) * (m - 2) << ' ';
      for (long long i = 1; i < m; i++) cout << 2 * (n - 2) << ' ';
      cout << '\n';
      for (long long i = 1; i < n; i++) {
        cout << 2 * (m - 2) << ' ';
        for (long long j = 1; j < m; j++) cout << "4 ";
        cout << '\n';
      }
    }
  }
  return 0;
}
