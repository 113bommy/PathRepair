#include <bits/stdc++.h>
using namespace std;
int n, m;
bool vis[20][20] = {};
pair<int, int> J1 = {0, 0}, J2{0, 0}, ans1, ans2;
string a[20][20], suits = "SCDH", ranks = "A23456789TJQK";
set<string> rep;
bool valid(int x, int y, int flag) {
  if (!flag) memset(vis, false, sizeof vis);
  set<char> cnt_suits, cnt_ranks;
  for (int i = x; i <= x + 2; i++)
    for (int j = y; j <= y + 2; j++) {
      if (flag && vis[i][j]) return false;
      cnt_ranks.insert(a[i][j][0]);
      cnt_suits.insert(a[i][j][1]);
      vis[i][j] = !flag;
    }
  return (cnt_ranks.size() == 9 || cnt_suits.size() == 1);
}
bool find_ans() {
  for (int i = 1; i <= n - 2; i++)
    for (int j = 1; j <= m - 2; j++)
      if (valid(i, j, false))
        for (int k = i; k <= n - 2; k++)
          for (int l = j; l <= m - 2; l++)
            if (valid(k, l, true)) {
              ans1 = {i, j};
              ans2 = {k, l};
              return true;
            }
  return false;
}
int main() {
  for (auto i : suits)
    for (auto j : ranks) {
      string t;
      t.push_back(j);
      t += i;
      rep.insert(t);
    }
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == "J1")
        J1 = {i, j};
      else if (a[i][j] == "J2")
        J2 = {i, j};
      else
        rep.erase(a[i][j]);
    }
  for (auto it1 : rep)
    for (auto it2 : rep)
      if (it1 != it2) {
        a[J1.first][J1.second] = it1;
        a[J2.first][J2.second] = it2;
        if (find_ans()) {
          cout << "Solution exists.\n";
          if (!J1.first && !J2.first)
            cout << "There are no jokers.\n";
          else if (J1.first && J2.first)
            cout << "Replace J1 with " << it1 << " and J2 with " << it2
                 << ".\n";
          else if (J1.first)
            cout << "Replace J1 with " << it1 << ".\n";
          else
            cout << "Replace J2 with " << it2 << ".\n";
          printf("Put the first square to (%d, %d).\n", ans1.first,
                 ans1.second);
          printf("Put the second square to (%d, %d).\n", ans2.first,
                 ans2.second);
          return 0;
        }
      }
  return cout << "No solution.\n", 0;
}
