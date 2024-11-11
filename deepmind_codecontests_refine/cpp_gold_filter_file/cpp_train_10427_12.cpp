#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
string t[6] = {"lios", "liala", "etr", "etra", "initis", "inites"};
bool mark[3];
int md = -1;
int typ(string s) {
  for (int i = 0; i < 6; i++)
    if (t[i].size() <= s.size()) {
      bool flag = true;
      for (int j = 0; j < t[i].size(); j++)
        if (t[i][j] != s[s.size() - t[i].size() + j]) flag = false;
      if (flag) return i;
    }
  return -1;
}
int main() {
  ios::sync_with_stdio(false);
  string s;
  bool flag = true;
  bool x = false;
  int cnt = 0;
  while (cin >> s) {
    cnt++;
    int p = typ(s);
    if (p == -1)
      flag = false, x = true;
    else if (md != -1 && p % 2 != md)
      flag = false;
    else if (p / 2 == 0 && (mark[1] || mark[2]))
      flag = false;
    else if (p / 2 == 1 && (mark[1] || mark[2]))
      flag = false;
    else if (p / 2 == 2 && !mark[1])
      flag = false;
    if (flag) {
      md = p % 2;
      mark[p / 2] = true;
    }
  }
  if ((!mark[1] && cnt > 1) || x || (cnt > 1 && !flag)) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  return 0;
}
