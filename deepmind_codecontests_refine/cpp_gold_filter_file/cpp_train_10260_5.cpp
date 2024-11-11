#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, m, a[maxn], Blk, blg[maxn], lis[maxn], tmp[maxn];
struct data {
  int L, R, id;
  bool operator<(const data &rhs) const {
    return blg[L] == blg[rhs.L] ? R < rhs.R : L < rhs.L;
  }
} q[maxn];
int cnt[maxn], f[maxn], g[maxn];
void Upd(int x, int val) {
  f[cnt[a[x]]]--;
  cnt[a[x]] += val;
  f[cnt[a[x]]]++;
}
priority_queue<int, vector<int>, greater<int> > Hp;
long long Calc() {
  int lst = 0;
  while (!Hp.empty()) Hp.pop();
  for (int i = 1; i < Blk; i++) g[i] = f[i];
  long long res = 0;
  for (int i = 1; i < Blk; i++)
    if (g[i]) {
      if (lst) {
        res += i + lst;
        if (i + lst < Blk)
          g[i + lst]++;
        else
          Hp.push(i + lst);
        g[i]--;
        lst = 0;
      }
      if (g[i] & 1) lst = i;
      res += (long long)(g[i] / 2) * (i * 2);
      if (i * 2 < Blk)
        g[i * 2] += g[i] / 2;
      else {
        for (int j = 1; j <= g[i] / 2; j++) Hp.push(i * 2);
      }
      g[i] = 0;
    }
  if (lst) Hp.push(lst);
  for (int i = 1; i <= lis[0]; i++)
    if (cnt[lis[i]] >= Blk) Hp.push(cnt[lis[i]]);
  while (Hp.size() > 1) {
    int x = Hp.top();
    Hp.pop();
    int y = Hp.top();
    Hp.pop();
    Hp.push(x + y);
    res += x + y;
  }
  return res;
}
long long ans[maxn];
int main() {
  scanf("%d", &n);
  Blk = sqrt(n) + 1;
  for (int i = 1; i <= n; i++) blg[i] = i / Blk;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (!tmp[a[i]]) f[0]++;
    if ((++tmp[a[i]]) == Blk) lis[++lis[0]] = a[i];
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &q[i].L, &q[i].R), q[i].id = i;
  sort(q + 1, q + 1 + m);
  for (int i = 1, L = 1, R = 0; i <= m; i++) {
    while (R < q[i].R) Upd(++R, 1);
    while (q[i].L < L) Upd(--L, 1);
    while (q[i].R < R) Upd(R--, -1);
    while (L < q[i].L) Upd(L++, -1);
    ans[q[i].id] = Calc();
  }
  for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
  return 0;
}
