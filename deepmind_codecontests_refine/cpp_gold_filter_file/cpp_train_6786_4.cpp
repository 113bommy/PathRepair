#include <bits/stdc++.h>
using namespace std;
long long T = 0, n = 0, m = 0, a, b, c;
pair<pair<long long, long long>, long long> d[1000001];
pair<long long, long long> tree[7000001];
long long mark[7000001];
void push_down(long long p) {
  if (!mark[p]) return;
  tree[p + p].first += mark[p];
  tree[p + p + 1].first += mark[p];
  mark[p + p] += mark[p];
  mark[p + p + 1] += mark[p];
  mark[p] = 0;
}
long long dc[1000001];
void modify(long long L, long long R, long long l, long long r, long long p,
            long long x) {
  if (L == l && R == r) {
    if (L == R) tree[p].second = dc[L];
    tree[p].first += x;
    mark[p] += x;
    push_down(p);
    return;
  }
  push_down(p);
  long long mid = (L + R) >> 1;
  if (r <= mid)
    modify(L, mid, l, r, p + p, x);
  else if (l >= mid + 1)
    modify(mid + 1, R, l, r, p + p + 1, x);
  else
    modify(L, mid, l, mid, p + p, x),
        modify(mid + 1, R, mid + 1, r, p + p + 1, x);
  tree[p] = max(tree[p + p], tree[p + p + 1]);
}
pair<long long, long long> query(long long L, long long R, long long l,
                                 long long r, long long p) {
  if (l == L && r == R) {
    return tree[p];
  }
  push_down(p);
  long long mid = (L + R) >> 1;
  if (r <= mid)
    return query(L, mid, l, r, p + p);
  else if (l >= mid + 1)
    return query(mid + 1, R, l, r, p + p + 1);
  else
    return max(query(L, mid, l, mid, p + p),
               query(mid + 1, R, mid + 1, r, p + p + 1));
}
long long ans = 0;
pair<long long, long long> ansp =
    pair<long long, long long>(13011111, 130111111);
long long fuck = 0;
int main() {
  d[0] = pair<pair<long long, long long>, long long>(
      pair<long long, long long>(-1, -1), 0);
  cin >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> a >> b >> c;
    if (a < 0 || b < 0) continue;
    if (b > a) swap(a, b);
    d[++n] = pair<pair<long long, long long>, long long>(
        pair<long long, long long>(b, a), c);
    dc[n] = a;
    fuck = max(fuck, a);
    fuck = max(fuck, b);
  }
  sort(d + 1, d + n + 1);
  sort(dc + 1, dc + n + 1);
  m = unique(dc + 1, dc + n + 1) - dc - 1;
  for (long long i = 1; i <= m; i++) modify(1, m, i, i, 1, -dc[i]);
  ansp = pair<long long, long long>(fuck + 1, fuck + 1);
  for (long long i = n; i >= 1; i--) {
    modify(1, m, lower_bound(dc + 1, dc + m + 1, (d[i].first.second)) - dc, m,
           1, d[i].second);
    if (d[i].first.first != d[i - 1].first.first) {
      pair<long long, long long> tans = query(
          1, m, lower_bound(dc + 1, dc + m + 1, (d[i].first.first)) - dc, m, 1);
      tans.first += d[i].first.first;
      if (tans.first > ans) {
        ans = tans.first;
        ansp.first = d[i].first.first;
        ansp.second = tans.second;
      }
    }
  }
  cout << ans << endl;
  cout << ansp.first << " " << ansp.first << " " << ansp.second << " "
       << ansp.second << endl;
}
