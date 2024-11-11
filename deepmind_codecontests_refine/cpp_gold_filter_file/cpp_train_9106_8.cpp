#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  int l = s.length();
  int f = l / k;
  if (l % k != 0) {
    cout << "NO";
    return 0;
  }
  for (int j = 0; j < l; j += f) {
    for (int i = j, x = 1; i <= j + (f / 2); i++, x++) {
      if (s[i] != s[j + f - x]) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
}
