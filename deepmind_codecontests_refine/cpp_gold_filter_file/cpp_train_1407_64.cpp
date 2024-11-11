#include <bits/stdc++.h>
using namespace std;
const int maxn = 100025;
const int maxm = 300025;
const int maxp = maxn + maxm;
int n, m, i, j, t, k, s, odd, ans[maxm], pt;
struct Question {
  int p1, p2, va, id;
} quer[maxm], tmpq[maxm];
inline int Min(int x, int y) { return x < y ? x : y; }
inline int Max(int x, int y) { return x > y ? x : y; }
struct Prior_Queue {
  priority_queue<int, vector<int> > rel, del;
  inline void clr() {
    while (rel.size() && del.size() && rel.top() == del.top())
      rel.pop(), del.pop();
  }
  inline void Push(int x) { rel.push(x); }
  inline void Pop(int x) {
    del.push(x);
    clr();
  }
  inline int Top() {
    clr();
    return rel.empty() ? -1 : rel.top();
  }
} Q;
bool cmp(Question x, Question y) { return x.va < y.va; }
int ch[maxp][2], fa[maxp], val[maxp], pla[maxp], mx[maxp], stk[maxp], siz[maxp],
    xu[maxp];
bool r[maxp];
inline bool ison(int x) {
  ch[0][0] = ch[0][1] = 0;
  return ch[fa[x]][0] == x || ch[fa[x]][1] == x;
}
inline void pushup(int x) {
  siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + (x <= n) + xu[x];
  mx[x] = Max(val[x], Max(mx[ch[x][0]], mx[ch[x][1]]));
  if (mx[x] == val[x])
    pla[x] = x;
  else if (mx[x] == mx[ch[x][0]])
    pla[x] = pla[ch[x][0]];
  else
    pla[x] = pla[ch[x][1]];
}
inline void pushr(int x) {
  r[x] ^= 1;
  swap(ch[x][0], ch[x][1]);
}
inline void pushdown(int x) {
  if (r[x]) {
    if (ch[x][0]) pushr(ch[x][0]);
    if (ch[x][1]) pushr(ch[x][1]);
    r[x] = 0;
  }
}
inline void rotate(int x) {
  int y = fa[x], z = fa[y], w = (x == ch[y][1]);
  if (ison(y)) ch[z][y == ch[z][1]] = x;
  fa[x] = z;
  fa[y] = x;
  ch[y][w] = ch[x][w ^ 1];
  ch[x][w ^ 1] = y;
  if (ch[y][w]) fa[ch[y][w]] = y;
  pushup(y);
  pushup(x);
}
inline void splay(int x) {
  int y, z;
  stk[z = 1] = y = x;
  while (ison(y)) stk[++z] = y = fa[y];
  while (z) pushdown(stk[z--]);
  while (ison(x)) {
    y = fa[x];
    z = fa[y];
    if (ison(y)) rotate((ch[y][1] == x) ^ (ch[z][1] == y) ? x : y);
    rotate(x);
  }
}
inline void access(int x) {
  int y = 0;
  while (x) {
    splay(x);
    xu[x] += siz[ch[x][1]] - siz[y];
    ch[x][1] = y;
    pushup(x);
    y = x;
    x = fa[x];
  }
}
inline void makeroot(int x) {
  access(x);
  splay(x);
  pushr(x);
}
inline int findroot(int x) {
  splay(x);
  while (ch[x][0]) x = ch[x][0], pushdown(x);
  splay(x);
  return x;
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; ++i) {
    scanf("%d%d%d", &quer[i].p1, &quer[i].p2, &quer[i].va);
    quer[i].id = i;
    tmpq[i] = quer[i];
  }
  sort(tmpq + 1, tmpq + m + 1, cmp);
  pt = 1;
  odd = n;
  for (i = 1; i <= n + m; ++i) {
    pla[i] = i;
    mx[i] = val[i] = (i > n ? i - n : 0);
    siz[i] = (i <= n);
  }
  for (i = m; i > 0; --i) {
    while (pt <= m && odd) {
      if (tmpq[pt].id > i) {
        ++pt;
        continue;
      }
      int x = tmpq[pt].p1, y = tmpq[pt].p2, bh = tmpq[pt].id;
      makeroot(x);
      access(y);
      if (findroot(y) == x) {
        if (mx[x] > bh) {
          int pl = pla[x];
          Q.Pop(mx[x]);
          splay(pl);
          Q.Push(bh);
          siz[pl] = xu[pl] = 0;
          fa[ch[pl][0]] = fa[ch[pl][1]] = 0;
          ch[pl][0] = ch[pl][1] = 0;
          makeroot(x);
          makeroot(y);
          fa[x] = fa[y] = bh + n;
          xu[bh + n] += siz[x] + siz[y];
          siz[bh + n] += siz[x] + siz[y];
        }
      } else {
        makeroot(y);
        odd += ((siz[x] + siz[y]) & 1) - (siz[x] & 1) - (siz[y] & 1);
        fa[x] = fa[y] = bh + n;
        Q.Push(bh);
        xu[bh + n] += siz[x] + siz[y];
        siz[bh + n] += siz[x] + siz[y];
      }
      ++pt;
    }
    if (odd) {
      while (i) ans[i] = -1, --i;
      break;
    }
    ans[i] = tmpq[pt - 1].va;
    if (Q.Top() == i) {
      int x = quer[i].p1, y = quer[i].p2;
      makeroot(x);
      access(y);
      splay(i + n);
      odd +=
          -(siz[i + n] & 1) + (siz[ch[i + n][0]] & 1) + (siz[ch[i + n][1]] & 1);
      xu[i + n] = siz[i + n] = 0;
      fa[ch[i + n][0]] = fa[ch[i + n][1]] = 0;
      ch[i + n][0] = ch[i + n][1] = 0;
      Q.Pop(i);
    }
  }
  for (i = 1; i <= m; ++i) printf("%d\n", ans[i]);
  return 0;
}
