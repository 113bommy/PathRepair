#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
vector<int> factor[1000005];
int ans[1000005];
void solve() {
  for (int i = 2; i < 1000005; i += 2) {
    for (int j = i; j < 1000005; j += i) {
      factor[j].push_back(i);
    }
  }
  bitset<200005> ans2 = 0;
  bitset<200005> tmp = 0;
  int n, first, second;
  scanf("%d %d %d", &n, &first, &second);
  int a[200005];
  for (int i = 0; i <= n; i++) {
    a[i] = i;
    scanf("%d", &a[i]);
    tmp[a[i]] = 1;
  }
  for (int i = 0; i <= n; i++) {
    ans2 |= tmp >> a[i];
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int xx;
    scanf("%d", &xx);
    if (ans[xx]) {
      printf("%d ", ans[xx]);
    } else {
      int res = -1;
      for (auto it : factor[xx]) {
        if (it / 2 > second && it / 2 <= first + second &&
            ans2[it / 2 - second]) {
          res = max(res, it);
        }
      }
      printf("%d ", ans[xx] = res);
    }
  }
  printf("\n");
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
