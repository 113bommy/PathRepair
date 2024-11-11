#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int a[26] = {0};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < s[i].length(); j++) {
        int x = s[i][j] - 'a';
        a[x]++;
      }
    }
    bool flag = true;
    for (int i = 0; i < 26; i++) {
      if (a[i] % n != 0) {
        flag = false;
        break;
      }
    }
    if (flag)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
}
