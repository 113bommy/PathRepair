#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n < 31) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES\n";
    n -= 30;
    if (n == 6 || n == 10 || n == 14) {
      n--;
      cout << 6 << " " << 10 << " " << 15 << " " << n << endl;
      continue;
    }
    cout << 6 << " " << 10 << " " << 15 << " " << n << endl;
  }
}
