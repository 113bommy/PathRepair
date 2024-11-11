#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const int N = 300100;
int a[N], n;
pair<int, int> seg[N << 2];
void build(int nd, int L, int R) {
  if (L == R) {
    seg[nd] = {a[L], L};
    return;
  }
  int mid = (L + R) >> 1;
  build(nd << 1, L, mid);
  build(nd << 1 | 1, mid + 1, R);
  seg[nd] = min(seg[nd << 1], seg[nd << 1 | 1]);
}
pair<int, int> query(int nd, int L, int R, int from, int to) {
  if (from <= L && R <= to) return seg[nd];
  if (from > R || to < L) return {inf, N};
  int mid = (L + R) >> 1;
  pair<int, int> leftAns = query(nd << 1, L, mid, from, to);
  pair<int, int> rightAns = query(nd << 1 | 1, mid + 1, R, from, to);
  return min(leftAns, rightAns);
}
int seg1[N << 2];
int lazy[N << 2];
void build1(int nd, int L, int R) {
  if (L == R) {
    seg1[nd] = inf;
    return;
  }
  int mid = (L + R) >> 1;
  build1(nd << 1, L, mid);
  build1(nd << 1 | 1, mid + 1, R);
  seg1[nd] = min(seg1[nd << 1], seg1[nd << 1 | 1]);
}
void push(int nd, int L, int R) {
  if (lazy[nd] == inf) return;
  seg1[nd] = min(lazy[nd], seg1[nd]);
  if (L != R) {
    lazy[nd << 1] = min(lazy[nd], lazy[nd << 1]);
    lazy[nd << 1 | 1] = min(lazy[nd], lazy[nd << 1 | 1]);
  }
  lazy[nd] = inf;
}
int query1(int nd, int L, int R, int from, int to) {
  push(nd, L, R);
  if (from <= L && R <= to) return seg1[nd];
  if (from > R || to < L) return inf;
  int mid = (L + R) >> 1;
  int leftAns = query1(nd << 1, L, mid, from, to);
  int rightAns = query1(nd << 1 | 1, mid + 1, R, from, to);
  return min(leftAns, rightAns);
}
void updateRange(int nd, int L, int R, int from, int to, int val) {
  push(nd, L, R);
  if (R < from || L > to) return;
  if (from <= L && R <= to) {
    lazy[nd] = val;
    push(nd, L, R);
    return;
  }
  int mid = (L + R) >> 1;
  updateRange(nd << 1, L, mid, from, to, val);
  updateRange(nd << 1 | 1, mid + 1, R, from, to, val);
  seg1[nd] = min(seg1[nd << 1], seg1[nd << 1 | 1]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    a[i + n] = a[i];
  }
  build(1, 1, n + n);
  build1(1, 1, n + n + n);
  for (int i = 1; i < N + N; i++) lazy[i] = inf;
  vector<pair<int, int> > v;
  for (int i = 1; i <= n; i++) {
    int lo = i + 1, hi = i + n, x = a[i] & 1 ? a[i] + 1 : a[i];
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      if (x > query(1, 1, n + n, i + 1, mid).first * 2)
        hi = mid;
      else
        lo = mid + 1;
    }
    pair<int, int> mn = query(1, 1, n + n, i + 1, lo);
    if (x > mn.first * 2) {
      v.push_back({i, mn.second - 1});
      v.push_back({i + n, mn.second + n - 1});
    }
  }
  sort(v.begin(), v.end());
  vector<int> ANS(n, -1);
  for (int i = n; i >= 1; i--) {
    while (v.size() && v.back().first >= i) {
      updateRange(1, 1, n + n, v.back().first, v.back().second,
                  v.back().second);
      v.pop_back();
    }
    int out = query1(1, 1, n + n, i, i + n);
    out -= i;
    out++;
    if (out >= N) out = -1;
    ANS[i - 1] = out;
  }
  for (int i = 0; i < n; i++) printf("%d%c", ANS[i], (i == n - 1 ? '\n' : ' '));
  return 0;
}
