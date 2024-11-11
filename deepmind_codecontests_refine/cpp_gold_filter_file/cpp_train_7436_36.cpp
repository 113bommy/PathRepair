#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, k = 0, i = 0, j = 0;
  char str[100];
  cin >> n >> k;
  cin >> str;
  if (k <= n - k) {
    for (i = 1; i < k; i++) {
      cout << "LEFT" << endl;
    }
    for (i = 0; i < strlen(str) - 1; i++) {
      cout << "PRINT " << str[i] << endl;
      cout << "RIGHT" << endl;
    }
    cout << "PRINT " << str[strlen(str) - 1] << endl;
  }
  if (k > n - k) {
    for (i = 0; i < n - k; i++) {
      cout << "RIGHT" << endl;
    }
    for (i = strlen(str) - 1; i > 0; i--) {
      cout << "PRINT " << str[i] << endl;
      cout << "LEFT" << endl;
    }
    cout << "PRINT " << str[0] << endl;
  }
  return 0;
}
