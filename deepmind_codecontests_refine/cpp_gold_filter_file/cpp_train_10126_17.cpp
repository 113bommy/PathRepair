#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int n;
  string s;
  string output = "";
  int check = 1;
  cin >> t;
  for (int l = 0; l < t; l++) {
    int array[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> s;
      for (int j = 0; j < s.length(); j++) array[s[j] - 97]++;
    }
    for (int k = 0; k < 26; k++) {
      if (array[k] % n != 0) {
        cout << "NO" << endl;
        check = 0;
        break;
      }
    }
    if (check == 1) cout << "YES" << endl;
    check = 1;
  }
  return 0;
}
