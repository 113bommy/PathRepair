#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n <= 30) {
      cout << "NO"
           << "\n";
    } else {
      if (n == 36) {
        cout << "YES"
             << "\n";
        cout << 6 << " " << 10 << " " << 15 << " " << 5 << "\n";
      } else if (n == 44) {
        cout << "YES"
             << "\n";
        cout << 6 << " " << 10 << " " << 15 << " " << 13 << "\n";
      } else if (n == 40) {
        cout << "YES"
             << "\n";
        cout << 6 << " " << 10 << " " << 15 << " " << 9 << "\n";
      } else {
        cout << "YES"
             << "\n";
        cout << 6 << " " << 10 << " " << 14 << " " << (n - 30) << "\n";
      }
    }
  }
  return 0;
}
