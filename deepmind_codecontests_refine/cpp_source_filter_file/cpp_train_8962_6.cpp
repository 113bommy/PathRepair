#include <bits/stdc++.h>
const int MX = 3e5 + 5;
int n, m;
int x[MX];
int y[MX];
long long ans[MX];
std::vector<int> no[MX];
std::pair<int, int> diff[MX];
long long prefix[MX];
long long suff[MX];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i] >> y[i];
    diff[i] = {y[i] - x[i], i};
  }
  std::sort(diff, diff + n);
  int u, v;
  for (int i = 1; i <= m; i++) {
    std::cin >> u >> v;
    no[u].push_back(v);
    no[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + y[diff[i].second];
  }
  for (int i = n; i >= 1; i--) {
    suff[i] = suff[i + 1] + x[diff[i].second];
  }
  for (int i = 1; i <= n; i++) {
    int u = diff[i].second;
    long long int cur = prefix[i - 1] + suff[i + 1] + 1LL * (i - 1) * x[u] +
                        1LL * (n - i) * y[u];
    for (int to : no[u]) {
      cur -= std::min(x[u] + y[to], x[to] + y[u]);
    }
    ans[u] = cur;
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " ";
  }
  std::cout << '\n';
}
