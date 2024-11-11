#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    string test1 = "";
    string test2 = "";
    for (int j = 0; j < n / 2; j++) {
      test1 += s[j];
    }
    for (int k = n / 2; k < n; k++) {
      test2 += s[k];
    }
    if (n % 2 != 0)
      cout << "NO" << endl;
    else {
      if (test1 == test2) {
        cout << "YES" << endl;
      } else {
        cout << "N0" << endl;
      }
    }
  }
  return 0;
}
