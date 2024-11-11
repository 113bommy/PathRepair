#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string stringhe[n];
  string alfabeto = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < n; i++) cin >> stringhe[i];
  for (int j = 0; j < n; j++) {
    sort(stringhe[j].begin(), stringhe[j].end());
    int l = stringhe[j].length();
    bool flag = false;
    for (int i = 0; i < 26 - l + 1; i++) {
      if (stringhe[j] == alfabeto.substr(i, l)) {
        flag = true;
      }
    }
    if (flag)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
