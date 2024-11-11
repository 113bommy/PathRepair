#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 11;
int n, jav;
string s[N];
int main() {
  bool c = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  int m = s[0].size();
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++)
      if (s[i][j] != s[i][0]) {
        jav = j;
        c = 1;
        break;
      }
    if (c == 1) break;
  }
  cout << jav << endl;
  return 0;
}
