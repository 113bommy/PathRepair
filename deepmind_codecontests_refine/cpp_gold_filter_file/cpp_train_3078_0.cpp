#include <bits/stdc++.h>
using namespace std;
const int N = 3072;
struct Node {
  int a, b, id;
  Node() {}
  Node(int a, int b, int id) : a(a), b(b), id(id) {}
  bool operator<(const Node f) const {
    if (a != f.a) return a > f.a;
    return b > f.b;
  }
} c[N];
vector<int> rf, rg;
pair<int, int> dp[N][N], f[N][N];
int res, n, p, s, a[N], b[N];
int main() {
  cin >> n >> p >> s;
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) scanf("%d", b + i);
  for (int i = 1; i <= n; i++) c[i] = Node(a[i], b[i], i);
  sort(c + 1, c + n + 1);
  for (int i = 1; i <= n; i++)
    for (int j = max(0, i - s); j <= min(i, p); j++) {
      if (j > 0)
        dp[i][j] =
            max(dp[i][j], pair<int, int>(dp[i - 1][j - 1].first + c[i].a, 1));
      if (i - j > 0)
        dp[i][j] =
            max(dp[i][j], pair<int, int>(dp[i - 1][j].first + c[i].b, 0));
    }
  for (int i = n; i >= 1; i--)
    for (int j = 1; j <= n - i + 1; j++)
      f[i][j] = max(pair<int, int>(f[i + 1][j].first, 0),
                    pair<int, int>(f[i + 1][j - 1].first + c[i].b, 1));
  for (int i = p; i <= p + s; i++)
    res = max(res, dp[i][p].first + f[i + 1][p + s - i].first);
  for (int i = p; i <= p + s; i++)
    if (dp[i][p].first + f[i + 1][p + s - i].first == res) {
      for (int u = i, v = p; u; v -= dp[u][v].second, u--)
        if (dp[u][v].second)
          rf.push_back(c[u].id);
        else
          rg.push_back(c[u].id);
      for (int u = i + 1, v = p + s - i; u <= n; v -= f[u][v].second, u++)
        if (f[u][v].second) rg.push_back(c[u].id);
      cout << res << endl;
      for (int i = 0; i < rf.size(); i++)
        printf("%d%c", rf[i], " \n"[i + 1 == rf.size()]);
      for (int i = 0; i < rg.size(); i++)
        printf("%d%c", rg[i], " \n"[i + 1 == rg.size()]);
      break;
    }
}
