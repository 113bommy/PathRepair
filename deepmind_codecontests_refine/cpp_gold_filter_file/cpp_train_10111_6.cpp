#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
namespace Edge {
int cnt, head[maxn];
struct ed {
  int next, to;
} e[maxn << 1];
void add(int u, int v) {
  e[++cnt] = (ed){head[u], v};
  head[u] = cnt;
  e[++cnt] = (ed){head[v], u};
  head[v] = cnt;
}
}  // namespace Edge
namespace Tzh {
long long n, g[maxn], num[maxn], ans[maxn], id[maxn], tot;
void work() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> g[i];
  for (int i = 1; i <= n; i++) {
    if (!id[g[i]]) {
      id[g[i]] = ++tot;
      num[g[i]] = n - g[i] - 1;
    } else {
      if (!num[g[i]]) {
        id[g[i]] = ++tot;
        num[g[i]] = n - g[i] - 1;
      } else
        num[g[i]]--;
    }
    ans[i] = id[g[i]];
  }
  if (*max_element(num, num + n + 1) > 0) {
    cout << "Impossible";
  } else {
    cout << "Possible" << endl;
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  }
  return;
}
}  // namespace Tzh
int main() {
  ios::sync_with_stdio(false);
  Tzh::work();
  return 0;
}
