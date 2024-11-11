#include <bits/stdc++.h>
using namespace std;
struct treap {
  int rt, node_cnt, X, Y, Z;
  struct node {
    int ch[2], pri, siz;
    long long val, tg1, tg2;
  } t[500005];
  void up(int now) {
    t[now].siz = t[t[now].ch[0]].siz + t[t[now].ch[1]].siz + 1;
  }
  void add(int now, long long k, long long b) {
    t[now].val += b + k * t[t[now].ch[0]].siz;
    if (t[now].siz != 1) {
      t[now].tg1 += k, t[now].tg2 += b;
    }
  }
  void down(int now) {
    if (t[now].ch[0]) add(t[now].ch[0], t[now].tg1, t[now].tg2);
    if (t[now].ch[1])
      add(t[now].ch[1], t[now].tg1,
          t[now].tg2 + t[now].tg1 * (t[t[now].ch[0]].siz + 1));
    t[now].tg1 = t[now].tg2 = 0;
  }
  void merge(int &now, int x, int y) {
    if (!(x && y)) {
      now = x | y;
      return;
    }
    if (t[x].pri < t[y].pri)
      now = x, down(x), merge(t[now].ch[1], t[now].ch[1], y);
    else
      now = y, down(y), merge(t[now].ch[0], x, t[now].ch[0]);
    up(now);
  }
  void split(int now, int &x, int &y, int sz) {
    if (!now) {
      x = y = 0;
      return;
    }
    if (t[t[now].ch[0]].siz >= sz)
      y = now, down(y), split(t[now].ch[0], x, t[now].ch[0], sz);
    else
      x = now, down(x),
      split(t[now].ch[1], t[now].ch[1], y, sz - t[t[now].ch[0]].siz - 1);
    up(now);
  }
  void del(int &now, int k) {
    down(now);
    if (t[t[now].ch[0]].siz >= k)
      del(t[now].ch[0], k);
    else {
      k -= t[t[now].ch[0]].siz;
      if (k == 1) {
        merge(now, t[now].ch[0], t[now].ch[1]);
        return;
      }
      del(t[now].ch[1], k - 1);
    }
    up(now);
  }
  long long kth(int now, int k) {
    down(now);
    if (t[t[now].ch[0]].siz >= k) return kth(t[now].ch[0], k);
    k -= t[t[now].ch[0]].siz;
    if (k == 1) return t[now].val;
    return kth(t[now].ch[1], k - 1);
  }
  void NEW(long long val) {
    t[++node_cnt].val = val;
    t[node_cnt].siz = 1;
    t[node_cnt].pri = rand();
  }
  void insert(int pos, long long val) {
    NEW(val);
    split(rt, X, Y, pos);
    merge(rt, X, node_cnt);
    merge(rt, rt, Y);
  }
  void modify(int x, long long k, long long b) {
    split(rt, X, Y, x);
    add(X, k, b);
    merge(rt, X, Y);
  }
  int find(int val) {
    if (kth(rt, 1) >= kth(rt, 2) + val) return -1;
    int mid, l = 1, r = t[rt].siz - 1;
    while (l < r) {
      mid = r - (r - l >> 1);
      if (kth(rt, mid) >= kth(rt, mid + 1) + mid * val)
        r = mid - 1;
      else
        l = mid;
    }
    return l;
  }
  void print(int now) {
    down(now);
    if (t[now].ch[0]) print(t[now].ch[0]);
    cout << t[now].val << " ";
    if (t[now].ch[1]) print(t[now].ch[1]);
  }
} T;
int n, i, b[500005], pos;
int main() {
  for (cin >> n, i = 1; i <= n; ++i) cin >> b[i];
  for (i = 1; i <= n + 1; ++i) T.insert(0, 0);
  for (i = n; i; --i) {
    if (b[i] >= 0)
      T.add(T.rt, b[i], 0), T.del(T.rt, 1);
    else {
      pos = T.find(b[i]);
      if (~pos) {
        T.insert(pos + 1, T.kth(T.rt, pos + 1)), T.modify(pos + 1, b[i], 0);
        T.del(T.rt, 1);
        T.del(T.rt, T.t[T.rt].siz);
      } else
        T.del(T.rt, T.t[T.rt].siz);
    }
  }
  cout << T.t[T.rt].val;
}
