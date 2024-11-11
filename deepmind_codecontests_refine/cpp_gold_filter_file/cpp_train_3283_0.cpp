#include <bits/stdc++.h>
using namespace std;
int main() {
  set<string> a;
  vector<string> vec;
  int fians[101] = {
      0,
  };
  int foans[101] = {
      0,
  };
  string t;
  while (cin >> t) {
    int k = -1;
    string con;
    int file = 0;
    for (int i = 0; i < t.size(); i++) {
      if (i == t.size() - 1) file++;
      if (t[i] == '\\' || i == t.size() - 1) {
        con += t.substr(k + 1, i - k);
        if (a.find(con) == a.end()) {
          if (k == 2) vec.push_back(con);
          a.insert(con);
          for (int j = 0; j < vec.size(); j++) {
            if (con.compare(0, vec[j].size(), vec[j]) == 0) {
              if (file)
                fians[j]++;
              else
                foans[j]++;
            }
          }
        }
        k = i;
      }
    }
  }
  int fimax = 0;
  int fomax = 0;
  for (int i = 0; i <= 100; i++) {
    if (fimax < fians[i]) fimax = fians[i];
    if (fomax < foans[i]) fomax = foans[i];
  }
  cout << fomax - 1 << ' ' << fimax;
  return 0;
}
