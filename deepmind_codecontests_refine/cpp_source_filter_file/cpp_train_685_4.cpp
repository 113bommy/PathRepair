#include <bits/stdc++.h>
using namespace std;
inline void rd(int &x) {
  static char c;
  x = 0;
  while (c = getchar(), c < 48)
    ;
  do x = (x << 3) + (x << 1) + (c ^ 48);
  while (c = getchar(), c > 47);
}
int n, m;
int sum[100005];
void Add(int x, int a) {
  for (; x <= n; x += x & -x) sum[x] += a;
}
void Update(int l, int r, int a) {
  Add(l, a);
  Add(r + 1, -a);
}
long long Query(int x) {
  long long tmp = 0;
  for (; x; x ^= x & -x) tmp += sum[x];
  return tmp + sum[0];
}
struct node {
  int x, y, f;
} Q[100005];
struct section {
  int x_l, x_r, y_l, y_r, v;
};
struct temp {
  int x, l, r, v, f;
  bool operator<(const temp &s) const {
    if (x == s.x)
      return f < s.f;
    else
      return x < s.x;
  }
} Tmp[100005 << 2];
vector<section> sec[100005];
int lst[100005];
long long Ans[100005];
set<int> S[100005];
set<int>::iterator it, pre, nxt;
vector<node> G[100005];
char op[10];
int val[100005];
void Init() {
  for (int i = (1), _t = (m); i <= _t; ++i)
    if (Q[i].f == 2) G[Q[i].y].push_back((node){Q[i].x, i});
  for (int i = (1), _t = (n); i <= _t; ++i) {
    if (lst[val[i]]) Update(1, lst[val[i]], i - lst[val[i]]);
    lst[val[i]] = i;
    for (int j = (0), _t = (G[i].size() - 1); j <= _t; ++j) {
      node t = G[i][j];
      Ans[t.y] = Query(t.x);
    }
  }
  for (int i = (1), _t = (n); i <= _t; ++i) S[val[i]].insert(i);
  for (int i = (1), _t = (m); i <= _t; ++i)
    if (Q[i].f == 1) {
      int x = Q[i].x, v = Q[i].y;
      nxt = pre = it = S[val[x]].find(x);
      if (it != S[val[x]].begin()) {
        pre--;
        nxt++;
        int pos = n;
        if (nxt != S[val[x]].end()) pos = (*nxt) - 1;
        sec[i].push_back((section){1, *pre, *it, pos, (*pre) - (*it)});
      }
      nxt = pre = it;
      nxt++;
      if (nxt != S[val[x]].end()) {
        int pos = 1;
        if (it != S[val[x]].begin()) {
          pre--;
          pos = (*pre) + 1;
        }
        sec[i].push_back((section){pos, *it, *nxt, n, (*it) - (*nxt)});
      }
      S[val[x]].erase(it);
      val[x] = v;
      S[val[x]].insert(x);
      nxt = pre = it = S[val[x]].find(x);
      if (it != S[val[x]].begin()) {
        pre--;
        nxt++;
        int pos = n;
        if (nxt != S[val[x]].end()) pos = (*nxt) - 1;
        sec[i].push_back((section){1, *pre, *it, pos, (*it) - (*pre)});
      }
      nxt = pre = it;
      nxt++;
      if (nxt != S[val[x]].end()) {
        int pos = 1;
        if (it != S[val[x]].begin()) {
          pre--;
          pos = (*pre) + 1;
        }
        sec[i].push_back((section){pos, *it, *nxt, n, (*nxt) - (*it)});
      }
    }
}
void CDQ(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1;
  int top = 0;
  for (int i = (l), _t = (mid); i <= _t; ++i)
    if (Q[i].f == 1) {
      for (int j = (0), _t = (sec[i].size() - 1); j <= _t; ++j) {
        Tmp[++top] =
            (temp){sec[i][j].x_l, sec[i][j].y_l, sec[i][j].y_r, sec[i][j].v, 1};
        Tmp[++top] = (temp){sec[i][j].x_r + 1, sec[i][j].y_l, sec[i][j].y_r,
                            -sec[i][j].v, 1};
      }
    }
  for (int i = (mid + 1), _t = (r); i <= _t; ++i)
    if (Q[i].f == 2) Tmp[++top] = (temp){Q[i].x, Q[i].y, Q[i].y, i, 2};
  sort(Tmp + 1, Tmp + top + 1);
  for (int i = (1), _t = (top); i <= _t; ++i) {
    if (Tmp[i].f == 1)
      Update(Tmp[i].l, Tmp[i].r, Tmp[i].v);
    else
      Ans[Tmp[i].v] += Query(Tmp[i].l);
  }
  CDQ(l, mid);
  CDQ(mid + 1, r);
}
int main() {
  rd(n);
  rd(m);
  for (int i = (1), _t = (n); i <= _t; ++i) rd(val[i]);
  for (int i = (1), _t = (m); i <= _t; ++i) rd(Q[i].f), rd(Q[i].x), rd(Q[i].y);
  Init();
  memset(sum, 0, sizeof(sum));
  CDQ(1, m);
  for (int i = (1), _t = (m); i <= _t; ++i)
    if (Q[i].f == 2) {
      if (Q[i].x == Q[i].y) Ans[i] = 0;
      printf("%lld\n", Ans[i]);
    }
  return 0;
}
