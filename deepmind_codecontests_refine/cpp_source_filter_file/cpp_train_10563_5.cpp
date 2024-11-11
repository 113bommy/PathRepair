#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  string r[a + 1][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> r[i][j];
    }
  }
  for (int i = 0; i < a; i++) {
    string s;
    cin >> s;
    int t = s.size();
    for (int i = 0; i < a; i++) {
      if (r[i][0] == s) {
        if (r[i][1].size() < t) {
          cout << r[i][1] << " ";
        } else {
          cout << s << " ";
        }
        break;
      }
    }
  }
}
