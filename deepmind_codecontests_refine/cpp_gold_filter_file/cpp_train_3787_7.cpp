#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int t;
  cin >> t;
  string s;
  cin >> s;
  for (int j = 0; j < t; j++) {
    int i = 0;
    while (i < n - 1) {
      if (s[i] == 'B' && s[i + 1] == 'G') {
        s[i] = 'G';
        s[i + 1] = 'B';
        i += 2;
      } else {
        i += 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << s[i];
  }
}
