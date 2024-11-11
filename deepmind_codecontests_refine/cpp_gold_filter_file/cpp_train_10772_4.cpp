#include <bits/stdc++.h>
using namespace std;
int main() {
  int length = 0, hamDistance = 0;
  string s, t;
  cin >> length >> s >> t;
  vector<vector<int> > p(26, vector<int>(26, 0));
  for (int i = 0; i < length; i++) {
    if (s[i] != t[i]) {
      hamDistance++;
      p[s[i] - 'a'][t[i] - 'a'] = i + 1;
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (p[i][j] && p[j][i]) {
        cout << (hamDistance - 2) << endl;
        cout << p[i][j] << " " << p[j][i] << endl;
        return 0;
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (p[i][j]) {
        for (int k = 0; k < 26; k++) {
          if (p[i][j] && p[j][k] && i != j && j != k) {
            cout << (hamDistance - 1) << endl;
            cout << p[i][j] << " " << p[j][k] << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << hamDistance << endl;
  cout << -1 << " " << -1 << endl;
  return 0;
}
