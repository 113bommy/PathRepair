#include <bits/stdc++.h>
using namespace std;
int s[100005];
int ans[100005];
struct node {
  int l, r;
  node() {}
  node(int l, int r) : l(l), r(r) {}
};
map<int, node> res;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }
  for (int i = 0; i < n; i++) {
    auto x = res.find(s[i]);
    if (x == res.end()) {
      int l = s[i], r = s[i];
      int z = 0;
      for (int j = s[i]; j >= 0 && z < k; j--, z++) {
        auto y = res.find(j);
        if (y == res.end()) {
          l = j;
        } else {
          if (y->second.l >= s[i] - k + 1) l = y->second.l;
          break;
        }
      }
      for (int j = l; j <= r; j++) {
        res[j] = node(l, r);
      }
      ans[i] = l;
    } else {
      ans[i] = x->second.l;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
