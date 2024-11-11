#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
struct node {
  int x, y;
  int len;
  bool operator<(const node& rhs) const { return len < rhs.len; }
} a[maxn];
vector<pair<int, int> > ans;
vector<int> G[maxn * 2];
int tag[maxn] = {0}, n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++)
    scanf("%d", &a[i].len), a[i].x = i * 2 - 1, a[i].y = i * 2;
  sort(a + 1, a + n + 1);
  int len = a[n].len;
  tag[1] = a[n].x;
  tag[1 + len] = a[n].y;
  G[len].push_back(a[n].y);
  for (int j = n - 1; j >= len; j--) {
    G[1].push_back(a[j].x);
    if (a[j].len > 1) {
      G[1 + a[j].len - 2].push_back(a[j].y);
    } else
      ans.push_back(make_pair(a[j].x, a[j].y));
  }
  for (int j = len - 1, i = 2; j >= 1; j--, i++) {
    G[i - 1].push_back(a[j].x);
    tag[i] = a[j].x;
    G[i + a[j].len - 1].push_back(a[j].y);
    if (!tag[i + a[j].len] && i + a[j].len > len + 1)
      tag[i + a[j].len] = a[j].y;
  }
  int max_ = len + len;
  for (int j = 1; j <= max_; j++) {
    int tj = tag[j];
    for (int k = 0; k < G[j].size(); k++) {
      ans.push_back(make_pair(tj, G[j][k]));
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
