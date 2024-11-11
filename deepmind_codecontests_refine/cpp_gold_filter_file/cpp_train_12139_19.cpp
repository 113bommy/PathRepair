#include <bits/stdc++.h>
using namespace std;
struct block {
  int l, r;
};
const int N = 1e5 + 10;
vector<int> sav[N];
block bl[320];
int a[N], pos[N], rec[N];
int pre[320][N];
int main() {
  int n, k, q, sz, tot, num, l, r, ans;
  scanf("%d %d", &n, &k);
  sz = (int)sqrt(n);
  tot = (n - 1) / sz + 1;
  for (int i = 1; i <= n; i++) pos[i] = (i - 1) / sz + 1;
  for (int i = 1; i <= tot; i++) {
    bl[i].l = (i - 1) * sz + 1;
    bl[i].r = min(n, i * sz);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    num = (int)sav[a[i]].size();
    if (num >= k)
      rec[i] = sav[a[i]][num - k];
    else
      rec[i] = 0;
    sav[a[i]].push_back(i);
    pre[pos[i]][rec[i]]++;
  }
  for (int i = 1; i <= tot; i++) {
    for (int j = 1; j <= n; j++) {
      pre[i][j] += pre[i][j - 1];
    }
  }
  scanf("%d", &q);
  ans = 0;
  for (int i = 1; i <= q; i++) {
    scanf("%d %d", &l, &r);
    l = (l + ans) % n + 1;
    r = (r + ans) % n + 1;
    if (l > r) swap(l, r);
    ans = 0;
    if (pos[l] == pos[r]) {
      for (int j = l; j <= r; j++) {
        if (rec[j] < l) ans++;
      }
    } else {
      for (int j = l; j <= bl[pos[l]].r; j++) {
        if (rec[j] < l) ans++;
      }
      for (int j = bl[pos[r]].l; j <= r; j++) {
        if (rec[j] < l) ans++;
      }
      for (int j = pos[l] + 1; j <= pos[r] - 1; j++) ans += pre[j][l - 1];
    }
    printf("%d\n", ans);
  }
  return 0;
}
