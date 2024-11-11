#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  string r[b + 1][3];
  for (int i = 0; i < b; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> r[i][j];
    }
  }
  for (int i = 0; i < a; i++) {
    string s;
    cin >> s;
    int t = s.size();
    for (int j = 0; j < b; j++) {
      if (r[j][0] == s) {
        if (r[j][1].size() < t) {
          cout << r[j][1] << " ";
        } else {
          cout << s << " ";
        }
        break;
      }
    }
  }
}
