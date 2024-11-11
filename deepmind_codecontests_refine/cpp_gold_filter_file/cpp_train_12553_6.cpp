#include <bits/stdc++.h>
using namespace std;
namespace Input {
const int BUF = 65536;
char buf[BUF];
char *head = buf, *tail = buf;
}  // namespace Input
inline char inputchar() {
  using namespace Input;
  if (head == tail) tail = (head = buf) + fread(buf, 1, BUF, stdin);
  return *head++;
}
inline void read(int &ret) {
  char ch = inputchar();
  while (ch < '0' || ch > '9') ch = inputchar();
  ret = ch - '0';
  ch = inputchar();
  while (ch >= '0' && ch <= '9') {
    ret = ret * 10 + ch - '0';
    ch = inputchar();
  }
}
struct Node {
  int high, id;
  Node() {}
  Node(int a, int b) : high(a), id(b) {}
  bool operator<(const Node &r) const { return high < r.high; }
};
struct Event {
  int l, r, high, type, id;
  Event() {}
  Event(int a, int b, int c, int d, int e)
      : l(a), r(b), high(c), type(d), id(e) {}
  bool operator<(const Event &r) const {
    return high == r.high ? type > r.type : high < r.high;
  }
};
const int MAXN = 100005;
const int MOD = 1e9 + 7;
set<Node> node[MAXN << 2];
Event event[MAXN << 1];
int high[MAXN], g[MAXN];
int h, w, n, u, l, r, s, tot = 0, ans = 0;
Node res;
void modify(int p, int ql, int qr, int l, int r, int id, bool ch) {
  if (l >= ql && r <= qr) {
    if (ch)
      node[p].insert(Node(high[id], id));
    else
      node[p].erase(Node(high[id], id));
    return;
  }
  int mid = (l + r) >> 1;
  if (ql <= mid) modify((p << 1), ql, qr, l, mid, id, ch);
  if (qr > mid) modify((p << 1 | 1), ql, qr, mid + 1, r, id, ch);
}
void query(int p, int pos, int l, int r) {
  if (node[p].size() > 0 && res < *node[p].rbegin()) res = *node[p].rbegin();
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (pos <= mid)
    query((p << 1), pos, l, mid);
  else
    query((p << 1 | 1), pos, mid + 1, r);
}
int query(int pos) {
  res = Node(-1, -1);
  query(1, pos, 1, w);
  return (res.id == -1 ? 1 : g[res.id]);
}
int main() {
  memset(g, 0, sizeof(g));
  read(h), read(w), read(n);
  for (int i = 1; i <= n; i++) {
    read(u), read(l), read(r), read(s);
    event[tot++] = Event(l, r, u, 1, i);
    if (u + s <= h) event[tot++] = Event(l, r, u + s, -1, i);
    high[i] = u;
  }
  sort(event, event + tot);
  for (int i = 0; i < tot; i++) {
    Event &cur = event[i];
    if (cur.type == 1) {
      if (cur.l == 1)
        g[cur.id] = 2 * query(cur.r + 1) % MOD;
      else if (cur.r == w)
        g[cur.id] = 2 * query(cur.l - 1) % MOD;
      else
        g[cur.id] = (query(cur.l - 1) + query(cur.r + 1)) % MOD;
      modify(1, cur.l, cur.r, 1, w, cur.id, 1);
    } else
      modify(1, cur.l, cur.r, 1, w, cur.id, 0);
  }
  for (int i = 1; i <= w; i++) ans = (ans + query(i)) % MOD;
  printf("%d\n", ans);
  return 0;
}
