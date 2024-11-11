#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 44) {
      cout << "YES\n" << 6 << " " << 10 << " " << 7 << " " << 21 << endl;
      continue;
    }
    if (n == 36) {
      cout << "YES\n" << 6 << " " << 10 << " " << 5 << " " << 15 << endl;
      continue;
    }
    if (n == 40) {
      cout << "YES\n" << 6 << " " << 10 << " " << 3 << " " << 21 << endl;
      continue;
    }
    if (n > 30) {
      cout << "YES\n" << 6 << " " << 10 << " " << 14 << " " << n - 30 << endl;
    } else {
      cout << "NO\n";
    }
  }
}
