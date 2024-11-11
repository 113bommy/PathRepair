#include <bits/stdc++.h>
using namespace std;
int t[200200], now, l, r, n, k, q, tem[200200];
inline int lb(int x) { return x & -x; }
inline void insert(int k) {
  for (; k < 200000; k += lb(k)) ++t[k];
};
inline int ask(int x) {
  int ans = 0;
  for (; x; x -= lb(x)) ans += t[x];
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &k, &q);
  for (int i = 1; i <= n; i++) scanf("%d%d", &l, &r), ++tem[l], --tem[r + 1];
  for (int i = 1; i <= 200000; ++i) {
    now += tem[i];
    if (now >= k) insert(i);
  }
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &l, &r);
    printf("%d\n", ask(r) - ask(l - 1));
  }
}
