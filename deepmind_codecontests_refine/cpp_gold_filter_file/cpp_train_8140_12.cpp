#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    char ch[200005];
    cin >> ch;
    int len = strlen(ch);
    if (len < 3) {
      cout << 0 << endl;
      cout << endl;
    } else {
      vector<int> v;
      for (int i = 0; i < len - 2; i++) {
        if (ch[i] == 'o' && ch[i + 1] == 'n' && ch[i + 2] == 'e') {
          v.push_back(i + 1);
          ch[i + 1] = 'x';
        } else if (ch[i] == 't' && ch[i + 1] == 'w' && ch[i + 2] == 'o') {
          if (i + 4 < len) {
            if (ch[i + 3] == 'n' && ch[i + 4] == 'e') {
              v.push_back(i + 2);
              ch[i + 2] = 'x';
            } else {
              v.push_back(i + 1);
              ch[i + 1] = 'x';
            }
          } else {
            v.push_back(i + 1);
            ch[i + 1] = 'x';
          }
        }
      }
      int sz = v.size();
      cout << sz << endl;
      for (int i = 0; i < sz; i++) cout << v[i] + 1 << " ";
      cout << endl;
    }
  }
  return 0;
}
