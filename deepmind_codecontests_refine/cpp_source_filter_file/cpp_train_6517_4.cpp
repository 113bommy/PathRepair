#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
int n;
int seg[4 * 100001];
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int a[100005];
pair<int, int> p[100005];
void del(int curr, int l, int r, int x) {
  if (l == r) {
    seg[curr] = 0;
    return;
  }
  int mid = (l + r) / 2;
  if (x <= mid) {
    del(curr * 2, l, mid, x);
  } else
    del(curr * 2 + 1, mid + 1, r, x);
  seg[curr] = seg[2 * curr] + seg[2 * curr + 1];
}
int f(int curr, int beg, int end) {
  if (beg == end) {
    seg[curr] = 1;
    return 1;
  }
  int mid = (beg + end) / 2;
  return seg[curr] = f(2 * curr, beg, mid) + f(2 * curr + 1, mid + 1, end);
}
int jnext(int curr, int beg, int end, int l, int r) {
  if (seg[curr] == 0) {
    return -1;
  }
  if (beg > r || end < l) return -1;
  if (beg == end) {
    if (seg[curr] == 1) {
      return beg;
    }
    return -1;
  }
  int mid = (beg + end) / 2;
  int l1 = jnext(2 * curr, beg, mid, l, r);
  if (l1 != -1) return l1;
  return jnext(2 * curr + 1, mid + 1, end, l, r);
}
int sum(int curr, int beg, int end, int l, int r) {
  if (beg > r || end < l) return 0;
  if (l <= beg && r >= end) return seg[curr];
  int mid = (beg + end) / 2;
  return sum(2 * curr, beg, mid, l, r) + sum(2 * curr + 1, mid + 1, end, l, r);
}
int main() {
  int i, j, fl, test;
  scanf("%d", &n);
  f(1, 1, n);
  long long ans = 0;
  int curr_pos = 1;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    p[i] = make_pair(a[i], i);
  }
  sort(p + 1, p + n + 1);
  for (i = 1; i <= n;) {
    int val = p[i].first;
    set<pair<int, int> > S;
    while (p[i].first == val) {
      S.insert(make_pair(p[i].second >= curr_pos ? p[i].second - curr_pos
                                                 : p[i].second + n - curr_pos,
                         p[i].second));
      i++;
      if (i == n) break;
    }
    set<pair<int, int> >::iterator it;
    for (it = S.begin(); it != S.end(); it++) {
      int pos = (*it).second;
      if (curr_pos <= pos) {
        ans += sum(1, 1, n, curr_pos, pos);
      } else
        ans += sum(1, 1, n, curr_pos, n) + sum(1, 1, n, 1, pos);
      int nex = jnext(1, 1, n, pos + 1, n);
      if (nex == -1) nex = jnext(1, 1, n, 1, n);
      curr_pos = nex;
      del(1, 1, n, pos);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
