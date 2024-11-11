#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int p[100010], q[100010];
vector<int> t[100010], v[100010];
int mn[100010];
bool flag[100010];
inline int dist(int x, int y) {
  if (p[x] - q[y] >= 0)
    return p[x] - q[y];
  else
    return q[y] - p[x];
}
int main() {
  scanf("%d%d%d%d", &n, &m, &x, &y);
  memset(mn, 63, sizeof(mn));
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &q[i]);
  q[n + 1] = 1e9;
  q[0] = -1e9;
  int pos = 1;
  for (int i = 1; i <= n; i++) {
    while (pos <= m && q[pos] <= p[i]) pos++;
    pos--;
    if (dist(i, pos) == dist(i, pos + 1)) {
      t[i].push_back(pos);
      t[i].push_back(pos + 1);
    } else if (dist(i, pos) < dist(i, pos + 1)) {
      t[i].push_back(pos);
    } else {
      t[i].push_back(pos + 1);
    }
  }
  for (int i = 1; i <= n; i++)
    if (t[i].size() == 1) {
      int t1 = t[i][0];
      v[t1].push_back(i);
      mn[t1] = min(mn[t1], dist(i, t1));
    }
  for (int i = 1; i <= n; i++)
    if (t[i].size() == 1) {
      if (dist(i, t[i][0]) > mn[t[i][0]]) flag[i] = 1;
    }
  for (int i = 1; i <= n; i++)
    if (t[i].size() == 2) {
      bool flag1 = 0, flag2 = 0;
      int cnt1 = 0, cnt2 = 0;
      int t1 = t[i][0], t2 = t[i][1], d = dist(i, t1);
      for (int j = 0; j < v[t1].size(); j++) {
        if (dist(v[t1][j], t1) < d) flag1 = 1;
        if (d < dist(v[t1][j], t1))
          if (flag[v[t1][j]] == 0) cnt1++;
      }
      for (int j = 0; j < v[t2].size(); j++) {
        if (dist(v[t2][j], t2) < d) flag2 = 1;
        if (d < dist(v[t2][j], t2))
          if (flag[v[t2][j]] == 0) cnt2++;
      }
      if (cnt1 + flag1 <= cnt2 + flag2) {
        if (flag1) flag[i] = 1;
        for (int j = 0; j < v[t1].size(); j++) {
          if (d < dist(v[t1][j], t1))
            if (flag[v[t1][j]] == 0) flag[v[t1][j]] = 1;
        }
        mn[t1] = min(mn[t1], dist(i, t1));
        v[t1].push_back(i);
      } else {
        if (flag2) flag[i] = 1;
        for (int j = 0; j < v[t2].size(); j++) {
          if (d < dist(v[t2][j], t2))
            if (flag[v[t2][j]] == 0) flag[v[t2][j]] = 1;
        }
        mn[t2] = min(mn[t2], dist(i, t2));
        v[t2].push_back(i);
      }
    }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans += flag[i];
  printf("%d", ans);
  return 0;
}
