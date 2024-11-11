#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, z = 0;
    string s;
    cin >> n >> s;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '8') {
        if (n - i - 1 >= 11) {
          cout << "YES" << endl;
          z = 1;
          break;
        }
      }
    }
    if (!z) cout << "NO" << endl;
  }
  return 0;
}
