#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
pair<long long, long long> tmp[300005];
double slope(pair<long long, long long> i, pair<long long, long long> j) {
  return 1.0 * (i.second - j.second) / (i.first - j.first);
}
long long F(pair<long long, long long> i, long long k) {
  return k * i.first + i.second;
}
struct Segment_Tree {
  vector<pair<long long, long long> > C[300005 << 2];
  long long pos[300005 << 2];
  void init(long long k) {
    pos[k] = 0;
    sort(C[k].begin(), C[k].end());
    long long siz = C[k].size(), top = 0;
    for (long long i = 0; i < siz; i++) {
      while (top > 1 &&
             slope(tmp[top - 1], tmp[top]) < slope(tmp[top - 1], C[k][i]))
        --top;
      tmp[++top] = C[k][i];
    }
    C[k].clear();
    for (long long i = 1; i <= top; i++) C[k].push_back(tmp[i]);
  }
  void modify(long long l, long long r, long long k, long long x, long long y,
              pair<long long, long long> val) {
    if (l >= x && r <= y) {
      C[k].push_back(val);
      return;
    }
    long long mid = (l + r) >> 1;
    if (x <= mid) modify(l, mid, k << 1, x, y, val);
    if (y > mid) modify(mid + 1, r, k << 1 | 1, x, y, val);
  }
  long long calc(long long k, long long x) {
    if (C[k].empty()) return -1e18;
    while (pos[k] + 1 < C[k].size() &&
           F(C[k][pos[k]], x) < F(C[k][pos[k] + 1], x))
      ++pos[k];
    return F(C[k][pos[k]], x);
  }
  long long query(long long l, long long r, long long k, long long x,
                  long long y) {
    if (l == r) return calc(k, y);
    long long res = calc(k, y), mid = (l + r) >> 1;
    if (x <= mid)
      res = max(res, query(l, mid, k << 1, x, y));
    else
      res = max(res, query(mid + 1, r, k << 1 | 1, x, y));
    return res;
  }
  void dfs(long long l, long long r, long long k) {
    puts("---------------");
    printf("%d %d %d\n", l, r, C[k].size());
    for (long long i = 0; i < C[k].size(); i++)
      printf("%d %d\n", C[k][i].first, C[k][i].second);
    puts("");
    puts("---------------");
    if (l == r) return;
    long long mid = (l + r) >> 1;
    dfs(l, mid, k << 1);
    dfs(mid + 1, r, k << 1 | 1);
  }
} T;
struct node {
  long long ID, time, x;
} q[300005];
long long n, opt[300005], x[300005], y[300005], be[300005], ed[300005], cnt,
    Ans[300005];
long long cmp(node a, node b) { return a.x < b.x; }
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) {
    opt[i] = read();
    if (opt[i] == 1) {
      x[i] = read();
      y[i] = read();
    } else if (opt[i] == 2) {
      x[i] = read();
      ed[x[i]] = i;
    } else {
      x[i] = read();
      ++cnt;
      q[cnt] = (node){cnt, i, x[i]};
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (opt[i] == 1) {
      if (ed[i])
        T.modify(1, n, 1, i, ed[i], make_pair(x[i], y[i]));
      else
        T.modify(1, n, 1, i, n, make_pair(x[i], y[i]));
    }
  }
  for (long long i = 1; i <= (n << 1); i++) T.init(i);
  sort(q + 1, q + 1 + cnt, cmp);
  for (long long i = 1; i <= cnt; i++)
    Ans[q[i].ID] = T.query(1, n, 1, q[i].time, q[i].x);
  for (long long i = 1; i <= cnt; i++) {
    if (Ans[i] == -1e18)
      puts("EMPTY SET");
    else
      printf("%lld\n", Ans[i]);
  }
}
