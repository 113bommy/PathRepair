#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int main() {
  cin >> n >> k;
  cin >> s;
  if (n - k < k - 1) {
    for (int i = k - 1; i < n; i++) {
      cout << "PRINT " << s[i] << "\n";
      if (i + 1 < n) cout << "RIGHT\n";
    }
    for (int i = n - 1; i > k - 2; i--)
      if (i - 1 >= 0) cout << "LEFT\n";
    for (int i = k - 2; i >= 0; i--) {
      cout << "PRINT " << s[i] << "\n";
      if (i - 1 >= 0) cout << "LEFT\n";
    }
  } else {
    for (int i = k - 1; i >= 0; i--) {
      cout << "PRINT " << s[i] << "\n";
      if (i - 1 >= 0) cout << "LEFT\n";
    }
    for (int i = 0; i < k; i++)
      if (i + 1 < n) cout << "RIGHT\n";
    for (int i = k; i < n; i++) {
      cout << "PRINT " << s[i] << "\n";
      if (i + 1 < n) cout << "RIGHT\n";
    }
  }
}
