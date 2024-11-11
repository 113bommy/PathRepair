#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
char ch[13][13];
int main() {
  int t, l, p;
  cin >> t;
  string s;
  while (t--) {
    bool b;
    cin >> s;
    int cnt = 0;
    v.clear();
    for (int i = 1; i <= 12; i++) {
      if (12 % i == 0) {
        p = 0;
        for (int j = 0; j < i; j++) {
          for (int k = 0; k < (12 / i); k++) {
            ch[j][k] = s[p++];
          }
        }
        for (int j = 0; j < (12 / i); j++) {
          b = true;
          for (int k = 0; k < i; k++) {
            if (ch[k][j] == 'O') {
              b = false;
              break;
            }
          }
          if (b) {
            cnt++;
            v.push_back(make_pair(i, 12 / i));
            break;
          }
        }
      }
    }
    cout << cnt << " ";
    for (int i = 0; i < v.size(); i++) {
      pair<int, int> p = v[i];
      cout << p.first << "x" << p.second << " ";
    }
    cout << endl;
  }
  return 0;
}
