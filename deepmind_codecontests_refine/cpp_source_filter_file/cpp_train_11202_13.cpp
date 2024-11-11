#include <bits/stdc++.h>
using namespace std;
string n, m, s;
int main() {
  bool flag = 0;
  cin >> n;
  cin >> m;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    flag = 0;
    for (int j = 0; j < n.size(); j++) {
      if (s[i] == n[j]) {
        flag = 1;
        cout << m[i];
      }
    }
    if (flag == 0) {
      for (int j = 0; j < n.size(); j++) {
        if ('a' + (s[i] - 'A') == n[j]) {
          flag = 1;
          cout << 'A' + (m[i] - 'a');
        }
      }
    }
    if (flag == 0) cout << s[i];
  }
  cout << endl;
}
