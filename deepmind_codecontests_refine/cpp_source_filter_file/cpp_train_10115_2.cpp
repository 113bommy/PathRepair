#include <bits/stdc++.h>
using namespace std;
const int mod = 1000003;
int main() {
  int n, m;
  vector<string> input;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    input.push_back(s);
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    bool first = true;
    bool dir = true;
    for (int j = 0; j < m; j++) {
      bool tempdir = true;
      if (input[i][j] == '.') continue;
      if (input[i][j] == '3' || input[i][j] == '4') {
        if (j % 2 == 0) {
          tempdir = false;
        }
      } else {
        if (j % 2 == 1) {
          tempdir = false;
        }
      }
      if (first) {
        first = false;
        dir = tempdir;
      }
      if (dir != tempdir) ans = 0;
    }
    if (first) ans = (ans * 2) % mod;
  }
  for (int j = 0; j < m; j++) {
    bool first = true;
    bool dir = true;
    for (int i = 0; i < n; i++) {
      bool tempdir = true;
      if (input[i][j] == '.') continue;
      if (input[i][j] == '1' || input[i][j] == '4') {
        if (j % 2 == 0) {
          tempdir = false;
        }
      } else {
        if (j % 2 == 1) {
          tempdir = false;
        }
      }
      if (first) {
        first = false;
        dir = tempdir;
      }
      if (dir != tempdir) ans = 0;
    }
    if (first) ans = (ans * 2) % mod;
  }
  cout << ans << endl;
  return 0;
}
