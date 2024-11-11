#include <bits/stdc++.h>
using namespace std;
const int MAX = 59;
bool mark[MAX * 2][2][MAX][MAX * 2];
int ans, m, n;
string s;
void dfs(int tur, int ori, int pri, int pos) {
  if (mark[tur][ori][pri][pos] || tur > n || pri > m) return;
  mark[tur][ori][pri][pos] = true;
  if (tur == n && pri == m) {
    ans = max(ans, abs(pos));
    return;
  }
  dfs(tur + 1, ori, pri + (s[tur] == 'T'), pos + (ori ? -1 : 1));
  dfs(tur + 1, 1 - ori, pri + (s[tur] == 'F'), pos);
  dfs(tur, ori, pri + 2, pos);
}
int main() {
  cin >> s >> m, n = s.length();
  dfs(0, 0, 0, 0);
  cout << ans;
}
