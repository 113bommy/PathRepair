#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
priority_queue<int> s;
int n, m, l, r, sn, w[N], cnt[N], siz[N], opt[N], len[N], fet[N];
struct query {
  int l, r, t;
  long long ans;
} q[N];
inline bool cmp(query a, query b) {
  if (a.l / sn == b.l / sn) return a.r < b.r;
  return a.l < b.l;
}
inline bool bmp(query a, query b) { return a.t < b.t; }
inline void add(int u, int x) { siz[cnt[u]]--, cnt[u] += x, siz[cnt[u]]++; }
int main() {
  scanf("%d", &n), sn = sqrt(n);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]), cnt[w[i]]++;
  for (int i = 1; i <= 1e5; i++)
    if (cnt[i] > sn) fet[++fet[0]] = i;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) q[i].t = i, scanf("%d%d", &q[i].l, &q[i].r);
  sort(q + 1, q + m + 1, cmp);
  q[0].l = -n;
  for (int i = 1; i <= m; i++) {
    if (q[i].l / sn != q[i - 1].l / sn) {
      memset(cnt, 0, sizeof(cnt));
      memset(siz, 0, sizeof(siz));
      l = q[i].l, r = q[i].l, add(w[l], 1);
    }
    while (l < q[i].l) add(w[l], -1), l++;
    while (q[i].l < l) add(w[l - 1], 1), l--;
    while (r < q[i].r) add(w[r + 1], 1), r++;
    long long ans = 0;
    int op = 0;
    len[0] = 0;
    for (int x = 1; x <= sn; x++) opt[x] = 0;
    for (int x = 1; x <= sn; x++) {
      long long z = opt[x] + siz[x];
      if (!z) continue;
      if (!op) {
        if (z & 1) {
          z--, op = x, ans = ans + x * z;
          if (x * 2 > sn)
            while (z > 0) z -= 2, len[++len[0]] = x * 2;
          else
            opt[x * 2] = opt[x * 2] + z / 2;
        } else {
          op = 0, ans = ans + x * z;
          if (x * 2 > sn)
            while (z > 0) z -= 2, len[++len[0]] = x * 2;
          else
            opt[x * 2] = opt[x * 2] + z / 2;
        }
      } else {
        if (z & 1) {
          z--, ans = ans + x * z;
          if (x * 2 > sn)
            while (z > 0) z -= 2, len[++len[0]] = x * 2;
          else
            opt[x * 2] = opt[x * 2] + z / 2;
          ans = ans + op + x;
          if (op + x > sn)
            len[++len[0]] = op + x;
          else
            opt[op + x] = opt[op + x] + 1;
          op = 0;
        } else {
          z -= 2, ans = ans + x * z;
          if (x * 2 > sn)
            while (z > 0) z -= 2, len[++len[0]] = x * 2;
          else
            opt[x * 2] = opt[x * 2] + z / 2;
          ans = ans + op + x;
          if (op + x > sn)
            len[++len[0]] = op + x;
          else
            opt[op + x] = opt[op + x] + 1;
          op = x;
        }
      }
    }
    if (op > 0) len[++len[0]] = op;
    for (int x = 1; x <= fet[0]; x++)
      if (cnt[fet[x]] > sn) len[++len[0]] = cnt[fet[x]];
    for (int x = 1; x <= len[0]; x++) s.push(-len[x]);
    while (len[0] > 1) {
      len[0]--;
      int a = s.top();
      s.pop();
      int b = s.top();
      s.pop();
      ans = ans - a - b;
      s.push(a + b);
    }
    if (len[0] == 1) s.pop();
    q[i].ans = ans;
  }
  sort(q + 1, q + m + 1, bmp);
  for (int i = 1; i <= m; i++) printf("%lld\n", q[i].ans);
  return 0;
}
