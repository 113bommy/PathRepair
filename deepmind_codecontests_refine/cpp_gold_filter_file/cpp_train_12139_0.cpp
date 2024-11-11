#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
int n, k, q, ans;
vector<int> lst[MAXN + 10];
vector<int> C[MAXN + 10];
inline int lowbit(int x) { return x & (-x); }
void update(int l, int r) {
  for (int o = l; o <= n; o += lowbit(o)) C[o].push_back(r);
}
int query(int l, int r) {
  int res = 0;
  for (int o = l; o; o -= lowbit(o))
    res += upper_bound(C[o].begin(), C[o].end(), r) -
           upper_bound(C[o].begin(), C[o].end(), l - 1);
  return res;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1, a; i <= n; ++i) {
    scanf("%d", &a);
    lst[a].push_back(i);
  }
  for (int i = 1; i <= MAXN; ++i) {
    for (int j = 0; j < (int)lst[i].size(); ++j) {
      if (j < k)
        update(1, lst[i][j]);
      else
        update(lst[i][j - k] + 1, lst[i][j]);
    }
  }
  for (int i = 1; i <= MAXN; ++i) sort(C[i].begin(), C[i].end());
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l = (l + ans) % n + 1;
    r = (r + ans) % n + 1;
    if (l > r) swap(l, r);
    printf("%d\n", ans = query(l, r));
  }
  return 0;
}
