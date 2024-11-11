#include <bits/stdc++.h>
using namespace std;
template <typename Tp>
void read(Tp &x) {
  x = 0;
  int op = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') op = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= op;
}
template <typename Tp>
void CMax(Tp &x, Tp y) {
  if (y > x) x = y;
}
template <typename Tp>
void CMin(Tp &x, Tp y) {
  if (y < x) x = y;
}
const int N = 2e5 + 20;
const int Lim = 2e5;
int n, m, p[N], h[N];
struct Segtree {
  int mx[N << 2], lim;
  void pushup(int x) { mx[x] = max(mx[(x << 1)], mx[(x << 1 | 1)]); }
  void Modify(int pos, int v, int x, int l, int r) {
    if (l == r) {
      mx[x] = v;
      return;
    }
    if (pos <= ((l + r) >> 1))
      Modify(pos, v, (x << 1), l, ((l + r) >> 1));
    else
      Modify(pos, v, (x << 1 | 1), ((l + r) >> 1) + 1, r);
    pushup(x);
  }
  int query(int L, int R, int x, int l, int r) {
    if (L <= l && r <= R) return mx[x];
    int ret = 0;
    if (L <= ((l + r) >> 1))
      CMax(ret, query(L, R, (x << 1), l, ((l + r) >> 1)));
    if (R > ((l + r) >> 1))
      CMax(ret, query(L, R, (x << 1 | 1), ((l + r) >> 1) + 1, r));
    return ret;
  }
  void Ins(int pos, int v) { Modify(pos, v, 1, 1, lim); }
  void Era(int pos) { Modify(pos, 0, 1, 1, lim); }
  int Ask(int L) { return query(L, lim, 1, 1, lim); }
  int Mx() { return mx[1]; }
} Position, Height;
set<pair<int, int> > pos, ht;
vector<int> bac;
void Del(int t) {
  Position.Era(p[t]);
  Height.Era(h[t]);
}
void Add(int t, int op) {
  int v = 0;
  if (op == 1)
    v = Position.Ask(p[t]);
  else
    v = Height.Ask(h[t]);
  Position.Ins(p[t], v + 1);
  Height.Ins(h[t], v + 1);
}
int main() {
  int op, x;
  read(n);
  read(m);
  Position.lim = n;
  Height.lim = 10 + Lim;
  for (int t = 1; t <= m; ++t) {
    read(op);
    if (op == 1) {
      read(p[t]);
      read(h[t]);
      h[t] = h[t] - t + Lim;
      for (auto i : ht) {
        if (i.first > h[t]) break;
        bac.push_back(i.second);
      }
      for (int i = (0); i <= (((int)(bac).size()) - 1); ++i) Del(bac[i]);
      bac.push_back(t);
      for (int i = (((int)(bac).size()) - 1); i >= (0); --i) Add(bac[i], 1);
      pos.insert(make_pair(p[t], t));
      ht.insert(make_pair(h[t], t));
      bac.clear();
    } else {
      read(x);
      set<pair<int, int> >::iterator it = pos.begin();
      while (--x) {
        bac.push_back((*it).second);
        it++;
      }
      bac.push_back((*it).second);
      for (int i = (0); i <= (((int)(bac).size()) - 1); ++i) Del(bac[i]);
      bac.pop_back();
      for (int i = (((int)(bac).size()) - 1); i >= (0); --i) Add(bac[i], 2);
      int k = (*it).second;
      pos.erase(it);
      ht.erase(make_pair(h[k], k));
      bac.clear();
    }
    printf("%d\n", Position.Mx());
  }
  return 0;
}
