#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
      cout << "NO" << endl;
      continue;
    }
    if (n == 2) {
      int num1 = s[0] - '0';
      int num2 = s[1] - '0';
      if (num2 > num1) {
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << num1 << " " << num2 << endl;
        continue;
      } else {
        cout << "NO" << endl;
        continue;
      }
    }
    if (n > 2) {
      cout << "YES";
      cout << 2 << endl;
      cout << s[0] << " ";
      for (int i = 1; i < n; ++i) {
        cout << s[i];
      }
      cout << endl;
    }
  }
}
