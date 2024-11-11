#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i;
  cin >> t;
  for (i = 0; i < t; i++) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int j, count1 = 0;
    for (j = 0; j < n; j++) {
      if (s[j] == '8' && (n - j + 1) > 11) {
        count1++;
        break;
      }
    }
    if (count1 == 1) {
      cout << "YES"
           << "\n";
    } else if (count1 == 0) {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
