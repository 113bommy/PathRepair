#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5e5 + 5;
int N, a[MAX_N], b[MAX_N];
int o[MAX_N], cnt;
void discrete() {
  for (int i = 1; i <= N; i++) o[i] = a[i];
  sort(&o[1], &o[N + 1]);
  cnt = unique(&o[1], &o[N + 1]) - o - 1;
  for (int i = 1; i <= N; i++) a[i] = lower_bound(&o[1], &o[cnt + 1], a[i]) - o;
}
set<pair<int, int> > Break;
vector<int> vec[MAX_N], del[MAX_N], ins[MAX_N];
void mdy(int l, int r, int v) {
  if (l > r) return;
  ins[l].push_back(v);
  del[r + 1].push_back(v);
}
struct node {
  int len, vl, vr;
  int ml, mr, mx;
  node() {}
  node(int v) {
    vl = vr = v;
    len = ml = mr = mx = 1;
  }
} t[MAX_N << 2];
node operator+(const node &a, const node &b) {
  node res;
  res.len = a.len + b.len;
  res.vl = a.vl, res.vr = b.vr;
  res.ml = a.ml, res.mr = b.mr;
  res.mx = max(a.mx, b.mx);
  if (a.vr ^ b.vl) {
    res.mx = max(res.mx, a.mr + b.ml);
    if (a.ml == a.len) res.ml += b.ml;
    if (b.mr == b.len) res.mr += a.mr;
  }
  return res;
}
void build(int o, int l, int r) {
  if (l == r) return (void)(t[o] = node(0));
  int mid = (l + r) >> 1;
  build((o << 1), l, mid);
  build((o << 1 | 1), mid + 1, r);
  t[o] = t[(o << 1)] + t[(o << 1 | 1)];
}
void modify(int o, int l, int r, int pos) {
  if (l == r) return (void)(t[o] = node(1));
  int mid = (l + r) >> 1;
  if (pos <= mid)
    modify((o << 1), l, mid, pos);
  else
    modify((o << 1 | 1), mid + 1, r, pos);
  t[o] = t[(o << 1)] + t[(o << 1 | 1)];
}
void flip(int x) {
  if (x == 1 || b[x] == b[x - 1]) Break.erase(make_pair(x, b[x]));
  if (x == N || b[x] == b[x + 1]) Break.erase(make_pair(x + 1, b[x]));
  b[x] ^= 1, modify(1, 1, N, x);
  if (x == 1 || b[x] == b[x - 1]) Break.insert(make_pair(x, b[x]));
  if (x == N || b[x] == b[x + 1]) Break.insert(make_pair(x + 1, b[x]));
}
void upd1(int x, int v) {
  auto it = Break.lower_bound(make_pair(x, 0));
  auto pre = it, nxt = it;
  if (x != 1) {
    --pre;
    if (pre->second)
      mdy(pre->first, x - 1, v);
    else
      mdy((pre->first + x) >> 1, x - 1, v);
  }
  if (x != N + 1) {
    ++nxt;
    if (nxt->second)
      mdy(x, nxt->first - 1, v);
    else
      mdy(x, (x + nxt->first) / 2 - 1, v);
  }
}
void upd2(int x, int v) {
  auto it = Break.lower_bound(make_pair(x, 0));
  auto pre = it, nxt = it;
  --pre;
  if (pre->second && nxt->second)
    mdy(pre->first, nxt->first - 1, v);
  else if (!pre->second && nxt->second)
    mdy((pre->first + nxt->first) >> 1, nxt->first - 1, v);
  else if (pre->second && !nxt->second)
    mdy(pre->first, (pre->first + nxt->first) / 2 - 1, v);
}
void upd(int x, int v) {
  if (x == 1 || b[x] == b[x - 1])
    upd1(x, v);
  else
    upd2(x, v);
  if (x == N || b[x] == b[x + 1])
    upd1(x + 1, v);
  else
    upd2(x + 1, v);
}
int ans;
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", a + i);
  discrete();
  for (int i = 1; i <= N; i++) vec[a[i]].push_back(i);
  for (int i = 1; i <= N + 1; i++) Break.insert(make_pair(i, 0));
  build(1, 1, N);
  for (int i = cnt; i; i--) {
    for (int x : vec[i]) flip(x);
    for (int x : vec[i]) upd(x, o[i]);
    ans = max(ans, t[1].mx);
  }
  printf("%d\n", (ans - 1) >> 1);
  static priority_queue<int> q, d;
  for (int i = 1; i <= N; i++) {
    for (int x : ins[i]) q.push(x);
    for (int x : del[i]) d.push(x);
    while (!q.empty() && !d.empty() && q.top() == d.top()) q.pop(), d.pop();
    assert(!q.empty());
    printf("%d ", q.top());
  }
  putchar('\n');
  return 0;
}
