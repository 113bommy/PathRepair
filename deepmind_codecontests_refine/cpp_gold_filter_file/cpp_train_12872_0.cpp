#include <bits/stdc++.h>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int n;
bool f[40];
char a[112345], b[112345];
int g[40][40];
vector<pair<int, int> > ans;
void dfs(int v) {
  f[v] = true;
  for (int i = 1; i <= 26; i++)
    if (g[v][i] == 1 && !f[i]) {
      ans.push_back(make_pair(v, i));
      dfs(i);
    }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  int i, j;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) cin >> b[i];
  for (i = 0; i <= 35; i++)
    for (j = 0; j <= 35; j++) g[i][j] = 0;
  for (i = 1; i <= n; i++)
    if (a[i] != b[i]) {
      int x = (int)a[i] - (int)'a' + 1;
      int y = (int)b[i] - (int)'a' + 1;
      g[x][y] = 1;
      g[y][x] = 1;
    }
  for (i = 1; i <= 26; i++) f[i] = false;
  for (i = 1; i <= 26; i++)
    if (!f[i]) dfs(i);
  cout << ans.size() << endl;
  for (i = 0; i < ans.size(); i++)
    cout << (char)(ans[i].first + (int)'a' - 1) << " "
         << (char)(ans[i].second + (int)'a' - 1) << endl;
  return 0;
}
