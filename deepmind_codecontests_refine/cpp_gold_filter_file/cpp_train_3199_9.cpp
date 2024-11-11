#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  char s[n + 1];
  for (i = 0; i < n; i++) cin >> s[i];
  if (n == 1) {
    if (s[0] == '0') {
      cout << "no";
      return 0;
    } else {
      cout << "yes";
      return 0;
    }
  }
  for (i = 0; i < n; i++) {
    if (i == n - 1) {
      if ((s[i - 1] == '0' && s[i] == '0') ||
          (s[i - 1] == '1' && s[i] == '1')) {
        cout << "no";
        return 0;
      }
    } else if (i == 0) {
      if ((s[i + 1] == '0' && s[i] == '0') ||
          (s[i + 1] == '1' && s[i] == '1')) {
        cout << "no";
        return 0;
      }
    } else {
      if ((s[i] == '0' && s[i - 1] == '0' && s[i + 1] == '0') ||
          (s[i] == '1' && (s[i - 1] == '1' || s[i + 1] == '1'))) {
        cout << "no";
        return 0;
      }
    }
  }
  cout << "yes";
}
