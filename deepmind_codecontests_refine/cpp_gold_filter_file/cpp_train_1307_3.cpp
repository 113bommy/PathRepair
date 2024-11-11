#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[20][20];
string ran = "23456789TJQKA";
string sui = "CDHS";
set<string> st;
int j1x = -1, j1y = -1, j2x = -1, j2y = -1;
inline bool ok(int x, int y) {
  set<char> ra, su;
  for (int i = x; i < x + 3; i++) {
    for (int j = y; j < y + 3; j++) {
      ra.insert(s[i][j][0]);
      su.insert(s[i][j][1]);
    }
  }
  return ra.size() == 9 || su.size() == 1;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < 4; j++) {
      string ss = "  ";
      ss[0] = ran[i];
      ss[1] = sui[j];
      st.insert(ss);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> s[i][j];
      if (s[i][j] != "J1" && s[i][j] != "J2")
        st.erase(s[i][j]);
      else if (s[i][j] == "J1")
        j1x = i, j1y = j;
      else
        j2x = i, j2y = j;
    }
  }
  for (set<string>::iterator it1 = st.begin(); it1 != st.end(); it1++) {
    if (j1x != -1) s[j1x][j1y] = (*it1);
    for (set<string>::iterator it2 = st.begin(); it2 != st.end(); it2++) {
      if (it1 == it2) continue;
      if (j2x != -1) s[j2x][j2y] = (*it2);
      vector<pair<int, int> > v;
      for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++)
          if (ok(i, j)) v.push_back(make_pair(i + 1, j + 1));
      }
      for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < i; j++) {
          if (abs(v[i].first - v[j].first) > 2 ||
              abs(v[i].second - v[j].second) > 2) {
            cout << "Solution exists.\n";
            if (j1x == -1 && j2x == -1) cout << "There are no jokers.\n";
            if (j1x == -1 && j2x != -1)
              cout << "Replace J2 with " << (*it2) << ".\n";
            if (j1x != -1 && j2x == -1)
              cout << "Replace J1 with " << (*it1) << ".\n";
            if (j1x != -1 && j2x != -1)
              cout << "Replace J1 with " << (*it1) << " and J2 with " << (*it2)
                   << ".\n";
            cout << "Put the first square to (" << v[i].first << ", "
                 << v[i].second << ").\n";
            cout << "Put the second square to (" << v[j].first << ", "
                 << v[j].second << ").\n";
            exit(0);
          }
        }
      }
    }
  }
  cout << "No solution.";
  return 0;
}
