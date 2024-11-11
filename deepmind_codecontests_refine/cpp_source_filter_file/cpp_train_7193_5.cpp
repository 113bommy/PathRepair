#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    q;
int s1, s2, n;
int x[101010], ne[101010], to[101010], st[101010], t[101010], ans[101010];
int kk[101010];
bool cmp(const int &a, const int &b) { return kk[a] < kk[b]; }
int mi[101010][17], ma[101010][17];
int nmi[101010], nma[101010];
int q1[101010], qn;
int h[101010];
bool vis[101010];
void init() {
  s1 = (int)pow(n, 1.0 / 3);
  s2 = (int)pow(n, 2.0 / 3);
  for (int i = 1; i <= n; i++) {
    ne[i] = i + 1;
    to[i] = min(i + s1, n);
    st[i] = to[i] - i;
    if (i < n) {
      nmi[i] = min(x[i], x[i + 1]);
      nma[i] = max(x[i], x[i + 1]);
      q.push(make_pair(nma[i] - nmi[i], i));
    }
  }
}
void update(int p, int k) {
  while (ne[p] <= n && ne[p] - p <= s2 && nma[p] - nmi[p] <= k) {
    ne[p]++;
    if (ne[p] <= n) {
      nmi[p] = min(nmi[p], x[ne[p]]);
      nma[p] = max(nma[p], x[ne[p]]);
    }
  }
  if (ne[p] <= n && ne[p] - p <= s1) q.push(make_pair(nma[p] - nmi[p], p));
  to[p] = p;
  st[p] = 0;
  qn = 0;
  q1[++qn] = p;
  while (ne[to[p]] <= n && ne[to[p]] - p <= s1) {
    to[p] = ne[to[p]];
    st[p]++;
    q1[++qn] = to[p];
  }
  vis[p] = true;
  h[p] = qn;
  for (int i = p - 1; i >= p - s1 && i > 0; i--)
    if (vis[ne[i]]) {
      vis[i] = true;
      while (q1[n] - i > s1) qn--;
      to[i] = q1[qn];
      h[i] = qn;
      st[i] = st[ne[i]] + 1 - h[ne[i]] + qn;
    }
  for (int i = p - s1; i <= p; i++) vis[i] = false;
}
pair<int, int> pa;
int hmi, hma;
int query(int k) {
  while (!q.empty()) {
    pa = q.top();
    if (pa.first > k) break;
    q.pop();
    update(pa.second, k);
  }
  int p = 1, ret = 0;
  while (p <= n) {
    if (ne[p] <= n && ne[p] - p <= s1) {
      ret += st[p];
      p = to[p];
    } else {
      while (ne[p] <= n && ne[p] - p <= s2 && nma[p] - nmi[p] <= k) {
        ne[p]++;
        nmi[p] = min(nmi[p], x[ne[p]]);
        nma[p] = max(nma[p], x[ne[p]]);
      }
      if (ne[p] - p <= s2) {
        p = ne[p];
        ret++;
      } else {
        hmi = hma = x[p];
        for (int i = 16; i >= 0; i--)
          if (p + (1 << i) <= n &&
              max(hma, ma[p + 1][i]) - min(hmi, mi[p + 1][i]) <= k) {
            hma = max(hma, ma[p + 1][i]);
            hmi = min(hmi, mi[p + 1][i]);
            p += (1 << i);
          }
        p++;
        ret++;
      }
    }
  }
  return ret - 1;
}
int main() {
  int w, qn;
  scanf("%d%d%d", &n, &w, &qn);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  for (int i = 1; i <= qn; i++) {
    scanf("%d", &kk[i]);
    kk[i] = w - kk[i];
    t[i] = i;
  }
  sort(t + 1, t + 1 + qn, cmp);
  for (int i = n; i >= 1; i--) {
    mi[i][0] = ma[i][0] = x[i];
    for (int j = 1; j <= 16; j++) {
      mi[i][j] = min(mi[i][j - 1], mi[i + (1 << j - 1)][j - 1]);
      ma[i][j] = max(ma[i][j - 1], ma[i + (1 << j - 1)][j - 1]);
    }
  }
  init();
  for (int i = 1; i <= qn; i++) ans[t[i]] = query(kk[t[i]]);
  for (int i = 1; i <= qn; i++) printf("%d\n", ans[i]);
  return 0;
}
