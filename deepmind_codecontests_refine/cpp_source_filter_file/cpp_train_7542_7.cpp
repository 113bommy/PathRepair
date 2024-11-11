#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> ans;
void F(string a, string b, string c, string d, string e, string f) {
  if (d.size() - a.size() + 1 == f.size() &&
      c.size() - b.size() + 1 == e.size() && a[0] == b[0] && a.back() == c[0] &&
      b.back() == d[0] && d[a.size() - 1] == c[b.size() - 1] &&
      d.back() == e[0] && c.back() == f[0] && e.back() == f.back()) {
    vector<vector<char>> Map(c.size(), vector<char>(d.size(), '.'));
    for (int i = 0; i < a.size(); i++) Map[0][i] = a[i];
    for (int i = 1; i < b.size(); i++) Map[i][0] = b[i];
    for (int i = 1; i < c.size(); i++) Map[i][a.size() - 1] = c[i];
    for (int i = 0; i < d.size(); i++) Map[b.size() - 1][i] = d[i];
    for (int i = b.size() - 1; i < c.size(); i++)
      Map[i].back() = e[i - b.size() + 1];
    for (int i = a.size() - 1; i < d.size(); i++)
      Map.back()[i] = f[i - a.size() + 1];
    if (!ans.size() || Map[0] < ans[0]) ans = Map;
  }
}
int main() {
  string words[6];
  for (auto& i : words) cin >> i;
  int inds[] = {0, 1, 2, 3, 4, 5, 6};
  do
    F(words[inds[0]], words[inds[1]], words[inds[2]], words[inds[3]],
      words[inds[4]], words[inds[5]]);
  while (next_permutation(inds, inds + 6));
  if (!ans.size())
    cout << "Impossible";
  else {
    for (int i = 0; i < ans.size(); i++) {
      for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j];
      cout << endl;
    }
  }
}
