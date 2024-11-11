#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    string tes1 = "";
    string tes2 = "";
    for (int j = 0; j < n / 2; j++) {
      tes1 += s[j];
    }
    for (int k = n / 2; k < n; k++) {
      tes2 += s[k];
    }
    if (n % 2 != 0)
      cout << "NO" << endl;
    else {
      if (tes1 == tes2) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
