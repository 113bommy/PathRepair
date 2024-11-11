#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5 + 5;
int n, m, sum;
int a[MaxN], sale[MaxN];
vector<int> G[MaxN];
bool check(int x) {
  for (int i = 1; i <= x; i++) sale[i] = 0;
  for (int i = 1; i <= n; i++) {
    if (G[i].size() == 0) continue;
    int l = 0, r = (int)G[i].size() - 1, mid;
    while (l != r) {
      mid = (l + r) / 2;
      if (G[i][mid] <= x)
        l = mid + 1;
      else
        r = mid;
    }
    sale[G[i][l]] += a[i];
  }
  int money = 0, buy = 0;
  for (int i = 1; i <= x; i++) {
    money++;
    buy += min(money, sale[i]);
    money -= min(money, sale[i]);
  }
  if (money >= 2 * (sum - buy))
    return true;
  else
    return false;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    G[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end());
  int l = sum, r = sum * 2, mid, ans;
  while (l != r) {
    mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else
      l = mid + 1;
  }
  printf("%d\n", l);
}
