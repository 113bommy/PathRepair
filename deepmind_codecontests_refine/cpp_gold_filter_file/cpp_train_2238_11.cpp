#include <bits/stdc++.h>
using namespace std;
const int maxn = 1100;
vector<pair<int, int> > order[maxn];
vector<int> ans;
int n, x, y;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    order[x / 1000].push_back(make_pair(y, i));
  }
  int c = 0;
  for (int i = 0; i < maxn; i++) {
    int sz = order[i].size();
    if (!sz) continue;
    c++;
    sort(order[i].begin(), order[i].end());
    if (c % 2) reverse(order[i].begin(), order[i].end());
    for (int j = 0; j < sz; j++) ans.push_back(order[i][j].second);
  }
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  puts("");
  return 0;
}
