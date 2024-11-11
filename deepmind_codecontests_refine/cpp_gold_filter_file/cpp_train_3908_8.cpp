#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005, maxs = maxn << 1, maxk = 21, sigma = 2,
          maxt = maxn << 2;
int n, tot, last, top;
int sum[maxn], link[maxs], len[maxs], nxt[maxs][sigma], stk[maxn];
int lc[maxt], rc[maxt], minn[maxt], cnt[maxt];
long long ans;
string s;
int extend(int last, int x) {
  int pos = last, now = ++tot, tmp, cln;
  len[now] = len[pos] + 1;
  while (pos != 0 && nxt[pos][x] == 0) nxt[pos][x] = now, pos = link[pos];
  if (pos == 0) {
    link[now] = 1;
    return now;
  }
  tmp = nxt[pos][x];
  if (len[tmp] == len[pos] + 1) {
    link[now] = tmp;
    return now;
  }
  cln = ++tot, len[cln] = len[pos] + 1;
  link[cln] = link[tmp], link[tmp] = link[now] = cln;
  nxt[cln][0] = nxt[tmp][0], nxt[cln][1] = nxt[tmp][1];
  while (pos != 0 && nxt[pos][x] == tmp) nxt[pos][x] = cln, pos = link[pos];
  return now;
}
inline void pushup(int now) {
  minn[now] = min(minn[lc[now]], minn[rc[now]]), cnt[now] = 0;
  if (minn[lc[now]] == minn[now]) cnt[now] += cnt[lc[now]];
  if (minn[rc[now]] == minn[now]) cnt[now] += cnt[rc[now]];
}
void build(int l, int r, int now) {
  if (l == r) {
    minn[now] = sum[l - 1], cnt[now] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  lc[now] = now << 1, rc[now] = now << 1 | 1;
  build(l, mid, lc[now]), build(mid + 1, r, rc[now]);
  pushup(now);
}
pair<int, int> query(int l, int r, int now, int L, int R) {
  if (L <= l && r <= R) return make_pair(minn[now], cnt[now]);
  int mid = (l + r) >> 1;
  if (mid >= R) return query(l, mid, lc[now], L, R);
  if (L > mid) return query(mid + 1, r, rc[now], L, R);
  pair<int, int> res1 = query(l, mid, lc[now], L, R),
                 res2 = query(mid + 1, r, rc[now], L, R);
  if (res1.first == res2.first)
    return make_pair(res1.first, res1.second + res2.second);
  return res1.first < res2.first ? res1 : res2;
}
int main() {
  scanf("%d", &n);
  cin >> s;
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (s[i - 1] == '(' ? 1 : -1);
  build(1, n, 1);
  last = tot = 1;
  for (int i = 1; i <= n; i++) {
    char c = s[i - 1];
    last = extend(last, c == ')');
    if (c == '(') stk[++top] = i;
    if (c == ')' && top > 0) stk[top] = 0, top--;
    int l = stk[top] + 1, r = len[last] - len[link[last]];
    if (l <= r) {
      pair<int, int> res = query(1, n, 1, l, r);
      if (res.first == sum[i]) ans += res.second;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
