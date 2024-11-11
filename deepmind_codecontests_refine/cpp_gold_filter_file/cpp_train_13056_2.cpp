#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
vector<pair<int, int> > ans;
int b[maxn], c[maxn], vis[maxn];
int main() {
  int n, hp, reg;
  scanf("%d%d%d", &n, &hp, &reg);
  for (int i = 0; i < n; i++) scanf("%d%d", &b[i], &c[i]);
  int cnt = hp, dmg = 0, t = 0;
  int flag = 0;
  while (cnt > 0) {
    cnt -= dmg;
    cnt += reg;
    cnt = min(hp, cnt);
    if (cnt <= 0) break;
    int p = -1;
    for (int i = 0; i < n; i++) {
      if (!vis[i] && b[i] * hp >= 100 * cnt) {
        if (p == -1 || c[i] > c[p]) {
          p = i;
        }
      }
    }
    if (p != -1) {
      vis[p] = 1;
      dmg += c[p];
      ans.push_back(make_pair(t, p + 1));
    } else {
      if (cnt == hp) {
        flag = 1;
        break;
      }
    }
    ++t;
  }
  if (flag) {
    printf("NO\n");
    return 0;
  } else {
    printf("YES\n");
    printf("%d %d\n", t, ans.size());
    for (int i = 0; i < ans.size(); i++) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }
  return 0;
}
