#include <bits/stdc++.h>
using namespace std;
namespace FGF {
const int N = 1e5 + 5;
int n, m;
int a[N], bel[N], B;
struct ques {
  int l, r, i;
} q[N];
int cnt[N], sum, ans[N], fl, lst[N], c[N], len[N], tot, nxt[N];
bool cmp(const ques &a, const ques &b) {
  return bel[a.l] ^ bel[b.l] ? bel[a.l] < bel[b.l] : a.r < b.r;
}
deque<int> Q[N];
int askk(int x) {
  if (cnt[x] == 1) return 1;
  if (cnt[x] && c[Q[x].front()] == c[Q[x].back()]) return 1;
  return 0;
}
void work() {
  scanf("%d", &n);
  B = sqrt(n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (!lst[a[i]])
      c[i] = ++tot;
    else
      (!len[a[i]] || len[a[i]] == i - lst[a[i]]) ? c[i] = c[lst[a[i]]]
                                                 : c[i] = ++tot;
    if (lst[a[i]]) nxt[lst[a[i]]] = i, len[a[i]] = i - lst[a[i]];
    lst[a[i]] = i, bel[i] = (i - 1) / B + 1;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &q[i].l, &q[i].r), q[i].i = i;
  sort(q + 1, q + m + 1, cmp);
  for (int i = 1, l = 1, r = 0; i <= m; i++) {
    while (l > q[i].l)
      fl -= askk(a[--l]), sum += (++cnt[a[l]] == 1), Q[a[l]].push_front(l),
          fl += askk(a[l]);
    while (r < q[i].r)
      fl -= askk(a[++r]), sum += (++cnt[a[r]] == 1), Q[a[r]].push_back(r),
          fl += askk(a[r]);
    while (l < q[i].l)
      fl -= askk(a[l]), sum -= (--cnt[a[l]] == 0), Q[a[l]].pop_front(),
          fl += askk(a[l++]);
    while (r > q[i].r)
      fl -= askk(a[r]), sum -= (--cnt[a[r]] == 0), Q[a[r]].pop_back(),
          fl += askk(a[r--]);
    ans[q[i].i] = sum + (fl == 0);
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
}  // namespace FGF
int main() {
  FGF::work();
  return 0;
}
