#include <bits/stdc++.h>
using namespace std;
vector<int> disc;
const int maxn = (int)2e6 + 10;
vector<int> v[maxn];
pair<int, int> input[maxn];
int vis[maxn];
int pre[maxn];
int find(int x) {
  int r = x;
  while (pre[r] != r) {
    r = pre[r];
  }
  int i = x, j;
  while (i != r) {
    j = pre[i];
    pre[i] = r;
    i = j;
  }
  return r;
}
void join(int x, int y) {
  int r_x = find(x), r_y = find(y);
  if (r_x != r_y) {
    if (r_x < r_y)
      pre[r_y] = r_x;
    else
      pre[r_x] = r_y;
  }
}
int flag[maxn];
int cnt[maxn];
set<int> q[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &input[i].first, &input[i].second);
  }
  for (int i = 0; i < n; i++) {
    disc.push_back(input[i].first);
    disc.push_back(input[i].second);
  }
  sort(disc.begin(), disc.end());
  disc.resize(unique(disc.begin(), disc.end()) - disc.begin());
  for (int i = 0; i <= 2 * n; i++) pre[i] = i;
  int flag2 = 0;
  for (int i = 0; i < n; i++) {
    int fi =
        lower_bound(disc.begin(), disc.end(), input[i].first) - disc.begin();
    int se =
        lower_bound(disc.begin(), disc.end(), input[i].second) - disc.begin();
    if (find(fi) != find(se))
      join(fi, se);
    else if (fi != se) {
      if (flag[find(fi)] == 0) {
        flag[find(fi)]++;
      } else {
        flag2 = 1;
      }
    }
  }
  for (int i = 0; i <= 2 * n; i++) {
    if (i != find(i) && flag[i]) {
      flag[i] = 0;
      flag[find(i)] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    int fi =
        lower_bound(disc.begin(), disc.end(), input[i].first) - disc.begin();
    int se =
        lower_bound(disc.begin(), disc.end(), input[i].second) - disc.begin();
    cnt[find(fi)]++;
    cnt[find(se)]++;
    q[find(fi)].insert(input[i].first);
    while (q[find(fi)].size() > 2) {
      q[find(fi)].erase(q[find(fi)].begin());
    }
    q[find(se)].insert(input[i].second);
    while (q[find(se)].size() > 2) {
      q[find(fi)].erase(q[find(fi)].begin());
    }
  }
  if (flag2 == 1) {
    puts("-1");
    return 0;
  }
  int maxx = 0;
  for (int i = 0; i < n; i++) {
    if (cnt[i] != 0) {
      if (flag[i] == 0) {
        maxx = max(maxx, *q[i].begin());
      } else {
        q[i].erase(q[i].begin());
        maxx = max(maxx, *q[i].begin());
      }
    }
  }
  printf("%d\n", maxx);
  return 0;
}
