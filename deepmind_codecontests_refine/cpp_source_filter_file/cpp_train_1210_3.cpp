#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long res = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
  return res * f;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x < 10)
    putchar(x + '0');
  else {
    write(x / 10);
    putchar(x % 10 + '0');
  }
}
struct node {
  int l, r;
  mutable long long val;
  node(int L, int R = -1, long long V = 0) : l(L), r(R), val(V) {}
  bool operator<(const node& q) const { return l < q.l; }
};
set<node> s;
inline long long fpow(long long a, long long b, long long mod) {
  long long s = 1;
  a %= mod;
  while (b) {
    if (b & 1) s *= a, s %= mod;
    a *= a, a %= mod;
    b >>= 1;
  }
  return s;
}
inline set<node>::iterator split(int x) {
  set<node>::iterator it = s.lower_bound(node(x));
  if (it != s.end() && it->l == x) return it;
  it--;
  int L = it->l, R = it->r;
  long long V = it->val;
  s.erase(it);
  s.insert(node(L, x - 1, V));
  return s.insert(node(x, R, V)).first;
}
inline void assign(int l, int r, long long val) {
  set<node>::iterator it2 = split(r + 1), it1 = split(l);
  s.erase(it1, it2);
  s.insert(node(l, r, val));
}
inline void add(int l, int r, long long val) {
  set<node>::iterator it2 = split(r + 1), it1 = split(l);
  for (; it1 != it2; it1++) it1->val += val;
}
inline int grank(int l, int r, int x) {
  set<node>::iterator it2 = split(r + 1), it1 = split(l);
  vector<pair<long long, int> > tmp;
  tmp.clear();
  for (; it1 != it2; it1++)
    tmp.push_back(make_pair(it1->val, it1->r - it1->l + 1));
  sort(tmp.begin(), tmp.end());
  for (vector<pair<long long, int> >::iterator it = tmp.begin();
       it != tmp.end(); it++) {
    x -= it->second;
    if (x <= 0) return it->first;
  }
}
inline long long sum(int l, int r, long long x, long long y) {
  set<node>::iterator it2 = split(r + 1), it1 = split(l);
  long long s = 0;
  for (; it1 != it2; it1++)
    s += (long long)(it1->r - it1->l + 1) * fpow(it1->val, x, y) % y, s %= y;
  return s;
}
int n, m;
long long seed, vmax, a[100010];
inline long long rnd() {
  long long res = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return res;
}
int main() {
  n = read(), m = read(), seed = read(), vmax = read();
  for (int i = 1; i <= n; i++) {
    a[i] = rnd() % vmax + 1;
    s.insert(node(i, i, a[i]));
  }
  s.insert(node(n + 1, n + 1, 0));
  for (int i = 1; i <= m; i++) {
    long long op, l, r, x, y;
    op = rnd() % 4 + 1, l = rnd() % n + 1, r = rnd() % n + 1;
    if (l > r) swap(l, r);
    if (op == 3)
      x = rnd() % (r - l + 1) + 1;
    else
      x = rnd() % vmax + 1;
    if (op == 4) y = rnd() % vmax + 1;
    if (op == 1)
      add(l, r, x);
    else if (op == 2)
      assign(l, r, x);
    else if (op == 3)
      write(grank(l, r, x)), putchar('\n');
    else if (op == 4)
      write(sum(l, r, x, y)), putchar('\n');
  }
  return 0;
}
