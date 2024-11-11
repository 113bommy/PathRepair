#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  int nearlyprimes[] = {6, 10, 14, 15, 21, 22};
  while (t--) {
    int n;
    cin >> n;
    if (n > 30) {
      if (n == 36 || n == 40 || n == 44) {
        cout << "YES"
             << "\n";
        cout << (n - 31) << " " << 6 << " " << 10 << " " << 15 << "\n";
      } else {
        cout << "YES"
             << "\n";
        cout << (n - 30) << " " << 6 << " " << 10 << " " << 14 << "\n";
      }
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
