#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
vector<pair<int, int> > v[555];
int vis[1234];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    memset(vis, 0, sizeof vis);
    for (int j = 1; j <= m; j++) {
      int x;
      scanf("%d", &x);
      if (!vis[x]) v[i].push_back(make_pair(x, i));
      vis[x] = 1;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans ^= v[i][0].first;
  for (int i = 1; i <= n; i++)
    if (v[i].size() > 1) {
      if (ans) {
        puts("TAK");
        for (int j = 1; j <= n; j++) printf("%d ", v[j][0].second);
        puts("");
      } else {
        puts("TAK");
        for (int j = 1; j <= n; j++) {
          if (i == j)
            printf("%d ", v[j][1].second);
          else
            printf("%d ", v[j][0].second);
        }
        puts("");
      }
      return 0;
    }
  if (!ans)
    puts("NIE");
  else {
    puts("TAK");
    for (int i = 1; i <= n; i++) printf("%d ", v[i][0].second);
    puts("");
  }
  return 0;
}
