#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m, k;
long long now, ans[maxn];
int a[maxn], cnt[maxn * 10], be[maxn];
struct node {
  int l, r, id;
  bool operator<(const node &oth) const {
    return be[l] ^ be[oth.l] ? be[l] < be[oth.l]
                             : ((be[l] & 1) ? r < oth.r : r > oth.r);
  }
} q[maxn];
inline void add(int x) {
  now += cnt[x ^ k];
  cnt[x]++;
}
inline void del(int x) {
  cnt[x]--;
  now -= cnt[x ^ k];
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int nn = sqrt((double)n);
  int num = (int)ceil((double)n / nn);
  for (int i = 1; i <= num; i++) {
    for (int j = (i - 1) * nn + 1; j <= i * nn && j <= n; j++) {
      be[j] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] ^= a[i - 1];
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &q[i].l, &q[i].r);
    q[i].l--;
    q[i].id = i;
  }
  sort(q + 1, q + m + 1);
  int l = 1, r = 0;
  for (int i = 1; i <= m; i++) {
    int ql = q[i].l, qr = q[i].r;
    while (l > ql) add(a[--l]);
    while (r < qr) add(a[++r]);
    while (l < ql) del(a[l++]);
    while (r > qr) del(a[r--]);
    ans[q[i].id] = now;
  }
  for (int i = 1; i <= m; i++) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
