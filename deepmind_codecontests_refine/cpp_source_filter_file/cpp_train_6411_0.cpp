#include <bits/stdc++.h>
using namespace std;
int get(string s) {
  if (s == "Anka") return 0;
  if (s == "Chapay") return 1;
  if (s == "Cleo") return 2;
  if (s == "Troll") return 3;
  if (s == "Dracul") return 4;
  if (s == "Snowy") return 5;
  return 6;
}
int mat[7][7];
vector<int> teams[3];
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first < b.first || (a.first == b.first && a.second > b.second))
    return 1;
  return 0;
}
pair<int, int> ans;
bool vis[7];
int a, b, c;
void bt(int cnt) {
  if (cnt == 7) {
    int lov = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < teams[i].size(); j++)
        for (int k = 0; k < teams[i].size(); k++)
          lov += mat[teams[i][j]][teams[i][k]];
    }
    int tmp1 = a / teams[0].size();
    int tmp2 = b / teams[1].size();
    int tmp3 = c / teams[2].size();
    int mx = max(abs(tmp3 - tmp2), max(abs(tmp1 - tmp2), abs(tmp1 - tmp3)));
    if (cmp(make_pair(mx, lov), ans)) ans = make_pair(mx, lov);
    return;
  }
  for (int i = 0; i < 7; i++) {
    if (vis[i]) continue;
    vis[i] = true;
    teams[0].push_back(i);
    bt(cnt + 1);
    teams[0].pop_back();
    teams[1].push_back(i);
    bt(cnt + 1);
    teams[1].pop_back();
    teams[2].push_back(i);
    bt(cnt + 1);
    teams[2].pop_back();
    vis[i] = false;
  }
}
int main() {
  int n;
  string s1, s2;
  ans.first = 500 * 500;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s1 >> s2 >> s2;
    mat[get(s1)][get(s2)] = true;
  }
  cin >> a >> b >> c;
  for (int i = 0; i < 7; i++) {
    teams[2].push_back(i);
    vis[i] = true;
    for (int j = 0; j < 7; j++) {
      if (vis[j]) continue;
      teams[1].push_back(j);
      vis[j] = true;
      for (int k = 0; k < 7; k++) {
        if (vis[k]) continue;
        teams[0].push_back(k);
        vis[k] = true;
        bt(3);
        vis[k] = false;
        teams[0].pop_back();
      }
      vis[j] = false;
      teams[1].pop_back();
    }
    vis[i] = false;
    teams[2].pop_back();
  }
  cout << ans.first << ' ' << ans.second << '\n';
  return 0;
}
