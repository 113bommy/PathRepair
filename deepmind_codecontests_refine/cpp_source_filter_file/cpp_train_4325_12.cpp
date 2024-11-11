#include <bits/stdc++.h>
using namespace std;
char s[10010];
int n;
int e[10010][2];
vector<string> ans;
bool vis[10010][2];
bool dp[10010][2];
bool dfs(int p, int pre) {
  if (p > n) return false;
  if (p == n) return dp[p][pre] = true;
  if (vis[p][pre]) return dp[p][pre];
  bool re = false;
  if (e[p][0] != -1 && (pre != 0 || e[p][0] != e[p - pre - 2][pre]))
    re |= dfs(p + 2, 0);
  if (e[p][1] != -1 && (pre != 1 || e[p][1] != e[p - pre - 3][pre]))
    re |= dfs(p + 3, 1);
  vis[p][pre] = true;
  return dp[p][pre] = re;
}
void get_val(int p) {
  if (p <= n - 2) e[p][0] = 26 * (s[p + 1] - 'a') + (s[p + 2] - 'a');
  if (p <= n - 3)
    e[p][1] =
        26 * 26 * (s[p + 1] - 'a') + 26 * (s[p + 2] - 'a') + (s[p + 3] - 'a');
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  memset(e, -1, sizeof(e));
  for (int i = 0; i <= n; i++) {
    get_val(i);
  }
  for (int i = 5; i <= n; i++) {
    if (dfs(i + 2, 0)) {
      string t;
      t.push_back(s[i + 1]);
      t.push_back(s[i + 2]);
      ans.push_back(t);
    }
    if (dfs(i + 3, 1)) {
      string t;
      t.push_back(s[i + 1]);
      t.push_back(s[i + 2]);
      t.push_back(s[i + 3]);
      ans.push_back(t);
    }
  }
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  cout << ans.size() << '\n';
  for (string t : ans) {
    cout << t << '\n';
  }
  getchar();
  getchar();
  return 0;
}
