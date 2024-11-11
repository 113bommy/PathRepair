#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, k, a[MAXN], ans[MAXN], op;
int idx[MAXN], pre[MAXN], nex[MAXN];
void del(int x) {
  int l = x, r = x;
  for (int i = 1; i <= k + 1; i++) {
    idx[a[l]] = idx[a[r]] = -1;
    ans[l] = ans[r] = op;
    l = pre[l], r = nex[r];
  }
  nex[l] = r, pre[l] = r;
  idx[0] = 0;
  op ^= 1;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    idx[a[i]] = i;
    pre[i] = i - 1, nex[i] = i + 1;
  }
  pre[0] = 0, nex[n + 1] = n + 1;
  int t = n;
  while (t) {
    while (idx[t] == -1) t--;
    del(idx[t]);
  }
  for (int i = 1; i <= n; i++) printf("%d", ans[i] + 1);
  return 0;
}
