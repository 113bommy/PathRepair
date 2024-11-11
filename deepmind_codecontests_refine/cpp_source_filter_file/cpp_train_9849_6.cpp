#include <bits/stdc++.h>
using namespace std;
int n, k;
int siz[200010];
int now[200010];
vector<pair<int, int> > ans;
int main() {
  scanf("%d%d", &n, &k);
  int x = n;
  for (int i = 1; i <= k; i++) now[i] = i;
  while (true) {
    for (int i = 1; i <= k && x > k; i++) {
      siz[i]++;
      ans.push_back(pair<int, int>(now[i], x));
      now[i] = x;
      x--;
    }
    if (x == k) break;
  }
  for (int i = 2; i <= k; i++) ans.push_back(pair<int, int>(now[1], now[i]));
  int res = 0;
  for (int i = 2; i <= k; i++) {
    if (i == 2)
      res = max(res, siz[1] + siz[i] + 1);
    else
      res = max(res, siz[1] + siz[i] + 2);
  }
  printf("%d\n", res);
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
}
