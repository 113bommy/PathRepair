#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, c;
    cin >> s >> c;
    int n = s.size(), m = c.size();
    for (int i = 0; i < n; i++) {
      char min = s[i];
      int index = i;
      for (int j = i + 1; j < n; j++) {
        if (s[j] < min) {
          min = s[j];
          index = j;
        }
      }
      if (s[index] < s[i]) {
        swap(s[i], s[index]);
        break;
      }
    }
    if (s < c)
      cout << s;
    else
      cout << "---";
    cout << "\n";
  }
  return 0;
}
