#include <bits/stdc++.h>
using namespace std;
map<int, pair<int, int> > memo[300005];
int pre[100003], res[100003];
int main() {
  int n;
  scanf("%d", &n);
  int mx = -1, lst = 0;
  for (int i = 1; i <= n; i += 1) {
    int v, c, l, r;
    scanf("%d%d%d%d", &v, &c, &l, &r);
    if (l == 0 || memo[c + l + r].count(l)) {
      pair<int, int> val_idx = memo[c + l + r][l];
      if (val_idx.first + v > memo[c + l + r][c + l].first) {
        memo[c + l + r][c + l].first = val_idx.first + v;
        memo[c + l + r][c + l].second = i;
        pre[i] = val_idx.second;
        if (r == 0 && val_idx.first + v > mx) {
          mx = val_idx.first + v;
          lst = i;
        }
      }
    }
  }
  int len = 0;
  for (; lst; lst = pre[lst]) res[len++] = lst;
  printf("%d\n", len);
  while (len--) printf("%d ", res[len]);
  return 0;
}
