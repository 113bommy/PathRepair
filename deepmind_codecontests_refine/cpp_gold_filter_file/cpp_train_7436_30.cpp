#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int main() {
  cin >> n >> k;
  cin >> s;
  if (2 * k <= n) {
    for (int i = 1; i < k; i++) cout << "LEFT" << endl;
    for (int i = 0; i < n - 1; i++) {
      cout << "PRINT " << s[i] << endl;
      cout << "RIGHT" << endl;
    }
    cout << "PRINT " << s[n - 1] << endl;
  } else {
    for (int i = 1; i <= n - k; i++) cout << "RIGHT" << endl;
    for (int i = n - 1; i > 0; i--) {
      cout << "PRINT " << s[i] << endl;
      cout << "LEFT" << endl;
    }
    cout << "PRINT " << s[0] << endl;
  }
}
