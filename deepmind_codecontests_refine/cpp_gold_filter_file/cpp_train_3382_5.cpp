#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
struct Node {
  int mx, add;
  Node *ch[2];
  Node() {}
  Node(int mx, int add) : mx(mx), add(add) { ch[0] = ch[1] = NULL; }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
int query(Node *rt, int ql, int qr, int l = 0, int r = inf) {
  if (!rt || ql > qr) return 0;
  if (ql <= l && r <= qr) return rt->mx;
  int ret = 0, mid = l + r >> 1;
  if (ql <= mid) ret = max(ret, query(rt->ch[0], ql, qr, l, mid));
  if (qr > mid) ret = max(ret, query(rt->ch[1], ql, qr, mid + 1, r));
  return ret + rt->add;
}
void up(Node *rt) {
  rt->mx =
      max((rt->ch[0] ? rt->ch[0]->mx : 0), (rt->ch[1] ? rt->ch[1]->mx : 0)) +
      rt->add;
}
void modify(Node *&rt, int ql, int v, int l = 0, int r = inf) {
  if (!rt) rt = new Node(0, 0);
  if (l == r) {
    rt->mx = v;
  } else {
    int mid = l + r >> 1;
    if (ql <= mid)
      modify(rt->ch[0], ql, v, l, mid);
    else
      modify(rt->ch[1], ql, v, mid + 1, r);
    up(rt);
  }
}
void insert(Node *&rt, int ql, int qr, int l = 0, int r = inf) {
  if (!rt) rt = new Node(0, 0);
  if (ql <= l && r <= qr) {
    rt->mx++;
    rt->add++;
  } else {
    int mid = l + r >> 1;
    if (ql <= mid) {
      insert(rt->ch[0], ql, qr, l, mid);
    }
    if (qr > mid) {
      insert(rt->ch[1], ql, qr, mid + 1, r);
    }
    up(rt);
  }
}
int main() {
  Node *rt = new Node(0, 0);
  int n, k, l, r;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &l, &r);
    l = max(0, l);
    if (r >= 0) {
      pq.push({r, l});
      pq.push({l, -2});
    }
  }
  int pre = -1, preValue = 0;
  while (!pq.empty()) {
    int l = pq.top().second, r = pq.top().first;
    pq.pop();
    if (l < 0) {
      if (pre == r) continue;
      int v = query(rt, 0, r - k);
      if (l == -2 || v > preValue) {
        modify(rt, r, v);
        pre = r;
        preValue = v;
        if (r + k <= inf) {
          pq.push({r + k, -1});
        }
      }
    } else {
      insert(rt, l, r);
    }
  }
  printf("%d\n", rt->mx);
  return 0;
}
