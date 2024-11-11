#include <bits/stdc++.h>
using namespace std;
int n, d;
vector<pair<int, int> > a, b;
int dp[500010];
vector<int> all;
bool by_se(const pair<int, int> &A, const pair<int, int> &B) {
  return make_pair(A.second, A.first) < make_pair(B.second, B.first);
}
const int N = 1000010;
struct Segment_tree {
  int T[4000010], tag[4000010];
  Segment_tree() { memset(T, 0, sizeof(T)), memset(tag, 0, sizeof(tag)); }
  void pushup(int now) { T[now] = max(T[now << 1], T[now << 1 | 1]); }
  void addtag(int now, int x) { tag[now] += x, T[now] += x; }
  void pushdown(int now) {
    if (!tag[now]) return;
    addtag(now << 1, tag[now]), addtag(now << 1 | 1, tag[now]);
    tag[now] = 0;
  }
  void Update(int now, int l, int r, int L, int R, int x) {
    if (l == L && r == R) {
      tag[now] += x, T[now] += x;
      return;
    }
    pushdown(now);
    int mid = l + r >> 1;
    if (R <= mid)
      Update(now << 1, l, mid, L, R, x);
    else if (L > mid)
      Update(now << 1 | 1, mid + 1, r, L, R, x);
    else
      Update(now << 1, l, mid, L, mid, x),
          Update(now << 1 | 1, mid + 1, r, mid + 1, R, x);
    pushup(now);
  }
  int Query(int now, int l, int r, int L, int R) {
    if (l == L && r == R) return T[now];
    pushdown(now);
    int mid = l + r >> 1;
    if (R <= mid) return Query(now << 1, l, mid, L, R);
    if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
    return max(Query(now << 1, l, mid, L, mid),
               Query(now << 1 | 1, mid + 1, r, mid + 1, R));
  }
  void Modify(int now, int l, int r, int x, int v) {
    if (l == r) {
      T[now] = max(T[now], v);
      return;
    }
    pushdown(now);
    int mid = l + r >> 1;
    if (x <= mid)
      Modify(now << 1, l, mid, x, v);
    else
      Modify(now << 1 | 1, mid + 1, r, x, v);
    pushup(now);
  }
} seg;
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return max(a.first, a.second) * 2 + (a.first < a.second) <
         max(b.first, b.second) * 2 + (b.first > b.second);
}
int main() {
  scanf("%d%d", &n, &d), all.push_back(d);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a.push_back(make_pair(x, y)), all.push_back(x), all.push_back(y);
  }
  sort(all.begin(), all.end()),
      all.resize(unique(all.begin(), all.end()) - all.begin());
  d = lower_bound(all.begin(), all.end(), d) - all.begin();
  for (auto &it : a) {
    it.first = lower_bound(all.begin(), all.end(), it.first) - all.begin();
    it.second = lower_bound(all.begin(), all.end(), it.second) - all.begin();
  }
  sort(a.begin(), a.end(), cmp);
  seg.Update(1, 0, N, 0, N, -0x3f3f3f3f), seg.Modify(1, 0, N, d, 0);
  for (auto it : a) {
    seg.Modify(1, 0, N, it.second,
               seg.Query(1, 0, N, 0, min(it.first, it.second)) + 1);
    if (it.second + 1 <= it.first)
      seg.Update(1, 0, N, it.second + 1, it.first, 1);
  }
  printf("%d\n", seg.Query(1, 0, N, 0, N));
  return 0;
}
