#include <bits/stdc++.h>
using namespace std;
struct P {
  int id;
  int w;
  int bool_;
} edge[100005];
pair<int, int> pair_[100005];
int dis[100005];
bool cmp(P a, P b) {
  if (a.w != b.w)
    return a.w < b.w;
  else
    return a.bool_ < b.bool_;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    dis[i] = 2;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &edge[i].w, &edge[i].bool_);
    edge[i].id = i;
  }
  sort(edge + 1, edge + 1 + m, cmp);
  int dic = 1;
  for (int i = 1; i <= m; i++) {
    if (edge[i].bool_ == 1) {
      pair_[edge[i].id] = make_pair(dic, dic + 1);
      dic++;
    } else {
      int tmp = dic;
      while (tmp - dis[tmp] < 1) {
        tmp--;
        if (tmp <= 0) {
          cout << "-1" << endl;
          return 0;
        }
      }
      pair_[edge[i].id] = make_pair(tmp, tmp - dis[tmp]);
      dis[tmp]++;
    }
  }
  for (int i = 1; i <= m; i++) {
    printf("%d %d\n", pair_[i].first, pair_[i].second);
  }
  return 0;
}
