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
    int i, ma = 0;
    for (i = 0; i < n;) {
      if (s[i] == 'A') {
        i++;
        int m = 0;
        while (s[i] != 'P') {
          i++;
          m++;
        }
        ma = max(m, ma);
      } else
        i++;
    }
    cout << ma << "\n";
  }
  return 0;
}
