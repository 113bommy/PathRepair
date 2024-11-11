#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
pair<pair<int, int>, int> E[N];
pair<int, int> ans[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int w, in;
    cin >> w >> in;
    E[i] = pair<pair<int, int>, int>(pair<int, int>(w, 1 - in), i);
  }
  sort(E + 1, E + 1 + m);
  if (E[1].first.second) return 0 * puts("-1");
  int a = 1, b = 3, c = 1;
  for (int i = 1; i <= m; ++i) {
    if (!E[i].first.second) {
      ans[E[i].second] = pair<int, int>(c, c + 1);
      ++c;
      continue;
    }
    if (2 * i > 1ll * c * (c + 1)) return 0 * puts("-1");
    ans[E[i].second] = pair<int, int>(a--, b);
    if (a < 1) ++b, a = b - 2;
  }
  if (c != n) return 0 * puts("-1");
  for (int i = 1; i <= m; ++i)
    cout << ans[i].first << " " << ans[i].second << "\n";
}
