#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int mod = 1e9 + 7;
const int maxn = 2e6 + 100;
const int maxm = 2e6 + 100;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
int a[maxn];
int n, m;
pair<int, int> s[maxn];
vector<int> v[maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &s[i].first, &s[i].second);
  }
  int ans = -inf;
  int res = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      int id = (i - 1) * n + j;
      int mx = i, mn = j;
      int cnt = 0;
      for (int k = 1; k <= m; k++) {
        if (s[k].first <= mn && s[k].second >= mn &&
            (s[k].first > mx || s[k].second < mx)) {
          cnt++;
          v[id].push_back(k);
        }
      }
      if (ans < a[mx] - a[mn] + cnt) {
        ans = a[mx] - a[mn] + cnt;
        res = id;
      }
    }
  }
  printf("%d\n%d\n", ans, v[res].size());
  for (int i = 0; i < (int)v[res].size(); i++) {
    printf("%d ", v[res][i]);
  }
  return 0;
}
