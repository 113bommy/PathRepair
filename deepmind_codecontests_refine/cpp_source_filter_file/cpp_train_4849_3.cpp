#include <bits/stdc++.h>
using namespace std;
vector<string> split(string s) {
  vector<string> R;
  R.push_back("");
  for (auto c : s) {
    if (c == '.' || c == ',' || c == '!' || c == '?' || c == ' ' || c == ':') {
      if (R.back() != "") R.push_back("");
    } else {
      R.back() += c;
    }
  }
  return R;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string names[n];
    map<string, int> lookup;
    for (int ctr1 = 0; ctr1 < n; ctr1++)
      cin >> names[ctr1], lookup[names[ctr1]] = ctr1;
    int m;
    cin >> m;
    int poss[m][n];
    memset(poss, 0, sizeof(poss));
    string lines[m];
    getline(cin, lines[0]);
    bool impossible = false;
    int user[m];
    memset(user, -1, sizeof(user));
    for (int ctr1 = 0; ctr1 < m; ctr1++) {
      getline(cin, lines[ctr1]);
      bool unk = false;
      if (lines[ctr1][0] == '?') unk = true;
      vector<string> sline = split(lines[ctr1]);
      if (unk) {
        for (int ctr2 = 0; ctr2 < sline.size(); ctr2++)
          if (lookup.count(sline[ctr2])) {
            poss[ctr1][lookup[sline[ctr2]]] = -1;
          }
      } else {
        int id = lookup[sline[0]];
        user[ctr1] = id;
        if (ctr1) {
          poss[ctr1 - 1][id] = -1;
        }
        if (ctr1 < n - 1) {
          poss[ctr1 + 1][id] = -1;
        }
        for (int ctr2 = 0; ctr2 < n; ctr2++) {
          poss[ctr1][ctr2] = ctr2 == id ? 1 : -1;
        }
      }
    }
    for (int ctr0 = 0; ctr0 < 100; ctr0++) {
      for (int ctr1 = 0; ctr1 < m; ctr1++) {
        if (user[ctr1] != -1) continue;
        int empty = 0;
        for (int ctr2 = 0; ctr2 < n; ctr2++) {
          empty += poss[ctr1][ctr2] == 0;
        }
        if (empty == 1) {
          for (int ctr2 = 0; ctr2 < n; ctr2++) {
            if (poss[ctr1][ctr2] == 0) {
              user[ctr1] = ctr2;
              if (ctr1) {
                poss[ctr1 - 1][ctr2] = -1;
              }
              if (ctr1 < n - 1) {
                poss[ctr1 + 1][ctr2] = -1;
              }
              poss[ctr1][ctr2] = 1;
            }
          }
        }
      }
    }
    for (int ctr1 = 0; ctr1 < m; ctr1++) {
      if (user[ctr1] == -1)
        for (int ctr2 = 0; ctr2 < n; ctr2++) {
          if (poss[ctr1][ctr2] == 0) {
            user[ctr1] = ctr2;
            if (ctr1 < n - 1) {
              poss[ctr1 + 1][ctr2] = -1;
            }
            poss[ctr1][ctr2] = 1;
            break;
          }
        }
      if (user[ctr1] == -1) impossible = true;
    }
    if (impossible) {
      cout << "Impossible\n";
      continue;
    }
    for (int ctr1 = 0; ctr1 < m; ctr1++) {
      if (lines[ctr1][0] == '?')
        cout << names[user[ctr1]] << lines[ctr1].substr(1);
      else
        cout << lines[ctr1];
      cout << "\n";
    }
  }
  return 0;
}
