#include <bits/stdc++.h>
using namespace std;
const long long LINF = 1e18;
const int INF = 1e9 + 7;
const int MXN = 1e6 + 1;
const int N = 1e3 + 1;
int n;
int a[MXN];
pair<int, int> g[MXN];
int main() {
  ios_base::sync_with_stdio(1);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    g[i] = make_pair(a[i], -1);
  }
  sort(g + 1, g + n + 1);
  for (int i = n; i >= 1; --i) g[i].second = n - i + 1;
  for (int i = 1; i <= n; ++i)
    for (int j = n; j >= 1; --j)
      if (g[j].first == a[i]) {
        cout << g[j].second << ' ';
        break;
      }
  return 0;
}
