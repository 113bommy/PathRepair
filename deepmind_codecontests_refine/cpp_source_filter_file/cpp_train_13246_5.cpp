#include <bits/stdc++.h>
using namespace std;
int A[100005];
set<int> st[100005];
void init() {
  for (int i = 2; i <= 100000; i++) {
    for (int j = 2; j * j <= i; j++) {
      if ((i % j) == 0) {
        st[i].insert(j);
        st[i].insert(i / j);
      }
    }
    st[i].insert(1);
  }
}
int d[100005];
signed main() {
  int t, x, k;
  init();
  scanf("%d", &t);
  int n;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &A[i]);
      d[i] = 0;
    }
    int ans = 1;
    d[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (auto x : st[i]) {
        if (A[x] < A[i]) {
          d[i] = max(d[x] + 1, d[i]);
        }
      }
      ans = max(ans, d[i]);
    }
    cout << ans << '\n';
  }
}
