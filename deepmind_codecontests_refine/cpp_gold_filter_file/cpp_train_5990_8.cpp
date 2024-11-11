#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
const int mod = 1e9 + 7;
int b[55];
vector<string> s[6];
set<string> x;
int main() {
  int n, q;
  string a, b, temp;
  set<string>::iterator iter;
  while (cin >> n >> q) {
    for (int i = 0; i <= 5; i++) s[i].clear();
    for (int i = 1; i <= q; i++) {
      cin >> b >> a;
      s[a[0] - 'a'].push_back(b);
    }
    a = "a";
    x.insert(a);
    int sum = 0, len = 1, minx;
    while (!x.empty()) {
      minx = 10;
      for (iter = x.begin(); iter != x.end(); iter++) {
        temp = *iter;
        if (temp.size() < minx) {
          minx = temp.size();
        }
      }
      x.erase(temp);
      if (temp.size() == n) {
        sum++;
        continue;
      } else {
        string ex = "";
        if (s[temp[0] - 'a'].size() > 0) {
          for (int j = 0; j < s[temp[0] - 'a'].size(); j++) {
            ex = "";
            for (int k = 0; k < temp.size(); k++) {
              if (k != 0)
                ex += temp[k];
              else
                ex += s[temp[0] - 'a'][j];
            }
            x.insert(ex);
          }
        }
      }
    }
    cout << sum << endl;
  }
  return 0;
}
