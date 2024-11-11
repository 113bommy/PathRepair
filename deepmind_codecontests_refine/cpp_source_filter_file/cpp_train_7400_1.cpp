#include <bits/stdc++.h>
const int maxn = 1e5 + 7;
int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n, k;
  std::set<std::pair<int, int> > t[maxn], s;
  std::cin >> n >> k;
  int u, v, w;
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    std::cin >> u >> v >> w;
    t[u].insert(std::make_pair(v, w));
    t[v].insert(std::make_pair(u, w));
  }
  for (int i = 1; i <= n; i++) {
    if (t[i].size() == 1) {
      s.insert(std::make_pair((*t[i].begin()).second, i));
    }
  }
  while (n > k && s.size() > 2) {
    auto i = *s.begin();
    s.erase(i);
    int cur = i.second;
    ans = i.first;
    n--;
    int nxt = (*t[cur].begin()).first;
    t[nxt].erase(t[nxt].lower_bound(std::make_pair(cur, 0)));
    if (t[nxt].size() == 1) {
      s.insert(std::make_pair((*t[nxt].begin()).second + ans, nxt));
    }
  }
  std::cout << ans << std::endl;
}
