#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 100 + 5;
int n, q, m, a[N], b[M];
struct Query {
  int ty, l, r;
} query[N];
void solve() {
  scanf("%d%d%d", &n, &q, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < q; i++)
    scanf("%d%d%d", &query[i].ty, &query[i].l, &query[i].r);
  for (int i = 0; i < m; i++) scanf("%d", &b[i]);
  vector<int> ans;
  for (int i = 0; i < m; i++) {
    int cur = b[i];
    for (int _ = q - 1; _ >= 0; _--) {
      int ty = query[_].ty, l = query[_].l, r = query[_].r;
      if (l <= cur && cur <= r) {
        if (ty == 1) {
          cur = cur == l ? r : cur - 1;
        } else {
          cur = r - cur + l;
        }
      }
    }
    ans.push_back(a[cur]);
  }
  for (auto it : ans) printf("%d ", it);
  puts("");
}
int main() {
  solve();
  return 0;
}
