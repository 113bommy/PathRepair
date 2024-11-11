#include <bits/stdc++.h>
const int N = 305;
std::pair<int, int> p[N];
bool help(std::pair<int, int> p) { return p.first == -1 || p.second == -1; }
bool match(std::pair<int, int> p, std::pair<int, int> q) {
  return (p.first == -1 || p.first == q.first) &&
         (p.second == -1 || p.second == q.second);
}
void read(int &x) {
  std::string s;
  std::cin >> s;
  x = s[0] == '?' ? -1 : std::stoi(s);
}
int ans[N], cnt[N][N], example[N][N], max[N];
bool e[N][N];
std::pair<int, int> need[N];
int n, m, help_num;
bool vis[N];
int bel[N];
bool dfs(int x) {
  for (int i = 1; i <= m; ++i)
    if (!vis[i] && e[x][i]) {
      vis[i] = 1;
      if (!bel[i] || dfs(bel[i])) {
        bel[i] = x;
        return 1;
      }
    }
  return 0;
}
void check(int c) {
  m = help_num = 0;
  std::memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; ++i) max[i] = -1;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= n; ++j) cnt[i][j] = e[i][j] = 0;
  for (int i = 1; i <= n; ++i)
    if (!help(p[i]))
      ++cnt[p[i].second][p[i].first],
          max[p[i].second] = std::max(max[p[i].second], p[i].first);
    else {
      ++help_num;
      if (p[i].second != -1) max[p[i].second] = std::max(max[p[i].second], 0);
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j < max[i]; ++j)
      if (!cnt[i][j]) {
        if (++m > help_num) return;
        need[m] = std::pair<int, int>(j, i);
      };
  for (int i = 1; i <= n; ++i)
    if (max[i] != -1)
      for (int j = cnt[i][0]; j == 0 || j % i != 0; ++j) {
        if (++m > help_num) return;
        need[m] = std::pair<int, int>(0, i);
      };
  for (int i = 1; i <= n; ++i)
    if (help(p[i]))
      for (int j = 1; j <= m; ++j)
        if (match(p[i], need[j])) e[i][j] = 1;
  for (int i = 1; i <= m; ++i) bel[i] = 0;
  int t = 0;
  for (int i = 1; i <= n; ++i) {
    std::memset(vis, 0, m + 1);
    if (dfs(i)) ++t;
  }
  if (t < m) return;
  for (int i = 1; i <= m; ++i) p[bel[i]] = need[i];
  for (int i = 1; i <= n; ++i)
    if (!help(p[i])) example[p[i].second][p[i].first] = i;
  for (int i = 1; i <= n; ++i)
    if (max[i] != -1) {
      int qq = 0, lst = 0, cnt = 0;
      for (int j = 1; j <= n; ++j)
        if (p[j].second == i && p[j].first == 0) {
          if (i == 1) {
            ans[j] = j;
          } else {
            if (!cnt)
              lst = j;
            else
              ans[qq] = j;
            if (++cnt == i) ans[j] = lst, cnt = 0;
            qq = j;
          }
        }
    }
  for (int i = 1; i <= n; ++i)
    if (p[i].first > 0 && p[i].second == -1) p[i].second = c;
  for (int i = 1; i <= n; ++i)
    if (p[i].second == -1) p[i] = std::pair<int, int>(0, 1), ans[i] = i;
  for (int i = 1; i <= n; ++i)
    if (p[i].first == -1) ans[i] = example[p[i].second][0];
  for (int i = 1; i <= n; ++i)
    if (p[i].first > 0) ans[i] = example[p[i].second][p[i].first - 1];
  for (int i = 1; i <= n; ++i) std::cout << ans[i] << ' ';
  std::cout << '\n', std::exit(0);
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n;
  for (int i = 1; i <= n; ++i) read(p[i].first), read(p[i].second);
  int id = 0;
  for (int i = 1; i <= n; ++i)
    if (p[i].first > p[id].first) id = i;
  if (p[id].second != -1)
    check(p[id].second);
  else
    for (int i = 1; i <= n; ++i) p[id].second = i, check(i);
  std::cout << "-1\n";
  return 0;
}
