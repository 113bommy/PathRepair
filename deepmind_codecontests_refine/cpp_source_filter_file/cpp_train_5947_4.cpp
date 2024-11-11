#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n <= 2)
    cout << "NO" << endl;
  else {
    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != s[i + 1]) {
        cout << "YES" << endl << s[i] << s[i + 1] << endl;
        flag = 1;
        break;
      }
    }
    if (flag == 0) cout << "NO" << endl;
  }
  return 0;
}
