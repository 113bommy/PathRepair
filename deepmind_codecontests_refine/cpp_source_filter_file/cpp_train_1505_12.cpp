#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T min(T &a, T &b) {
  return a < b ? a : b;
}
template <class T>
inline T max(T &a, T &b) {
  return a > b ? a : b;
}
const int N = 1200000;
multiset<int, greater<int> > all[N];
int n, x, dp[N], fa[N];
void update(int x) {
  while (1) {
    int cur;
    multiset<int, greater<int> >::iterator It = all[x].begin();
    if (all[x].size() == 1 || x == 1)
      cur = *It;
    else
      cur = *It + 1, It++, cur = max(cur, *It);
    if (x == 1) {
      dp[1] = cur;
      break;
    }
    if (cur != dp[x]) {
      all[fa[x]].erase(dp[x]);
      dp[x] = cur;
      all[fa[x]].insert(dp[x]);
      x = fa[x];
    } else
      break;
  }
}
int main() {
  scanf("%d", &n);
  n++;
  for (int i = 2; i <= n; i++) {
    scanf("%d", &x);
    fa[i] = x;
    dp[i] = 1;
    all[x].insert(1);
    update(x);
    printf("%d\n", dp[1]);
  }
}
