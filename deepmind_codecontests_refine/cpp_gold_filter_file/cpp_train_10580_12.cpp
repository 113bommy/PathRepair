#include <bits/stdc++.h>
using namespace std;
long long modExp(long long a, long long b, long long m) {
  if (b == 0) return 1;
  long long c = modExp(a, b / 2, m);
  c = (c * c) % m;
  if (b % 2 != 0) c = (c * a) % m;
  return c;
}
struct node {
  int l, r;
  long long x;
  node(int _l, int _r, long long _x) : l(_l), r(_r), x(_x) {}
};
bool operator<(node a, node b) { return a.l < b.l; }
class IntervalTree {
  set<node> tree;
  set<node>::iterator it;
  void split(int i) {
    it = --tree.upper_bound(node(i, i, 0));
    if (it->l < i && it->r >= i) {
      node n1 = node(i, it->r, it->x);
      node n2 = *it;
      n2.r = i - 1;
      tree.erase(it);
      tree.insert(n1);
      tree.insert(n2);
    }
  }

 public:
  IntervalTree(int n) { tree.insert(node(0, n - 1, 0)); }
  IntervalTree(long long *st, long long *en) {
    for (int i = 0; st + i != en; i++) {
      tree.insert(node(i, i, st[i]));
    }
  }
  void add(int l, int r, long long x) {
    split(l);
    split(r + 1);
    it = tree.lower_bound(node(l, l, 0));
    while (it != tree.end() && it->l <= r) {
      node n = *it;
      n.x += x;
      it = tree.erase(it);
      tree.insert(n);
    }
  }
  void set(int l, int r, long long x) {
    split(l);
    split(r + 1);
    it = tree.lower_bound(node(l, l, 0));
    while (it != tree.end() && it->l <= r) {
      it = tree.erase(it);
    }
    tree.insert(node(l, r, x));
  }
  long long pw(int l, int r, long long p, long long m) {
    split(l);
    split(r + 1);
    long long ans = 0, cur;
    it = tree.lower_bound(node(l, l, 0));
    while (it != tree.end() && it->l <= r) {
      cur = ((it->r - it->l + 1) * modExp(it->x % m, p, m)) % m;
      ans = (ans + cur) % m;
      it++;
    }
    return ans;
  }
  long long nth(int l, int r, int k) {
    split(l);
    split(r + 1);
    map<long long, int> cnt;
    it = tree.lower_bound(node(l, l, 0));
    while (it != tree.end() && it->l <= r) {
      cnt[it->x] += it->r - it->l + 1;
      it++;
    }
    while (!cnt.empty() && k > 0) {
      int d = min(k, cnt.begin()->second);
      k -= d;
      cnt.begin()->second -= d;
      if (cnt.begin()->second == 0) {
        cnt.erase(cnt.begin());
      }
    }
    return cnt.begin()->first;
  }
};
int n, m;
long long seed, vmax;
long long a[1000009];
int rnd() {
  int ret = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return ret;
}
int main() {
  scanf("%d %d %I64d %I64d", &n, &m, &seed, &vmax);
  for (int i = 0; (i) < (n); (i)++) a[i] = (rnd() % vmax) + 1;
  IntervalTree it(a, a + n);
  for (int j = 0; (j) < (m); (j)++) {
    int op = (rnd() % 4) + 1;
    int l = (rnd() % n);
    int r = (rnd() % n);
    if (l > r) swap(l, r);
    long long x;
    if (op == 3) {
      x = (rnd() % (r - l + 1)) + 1;
    } else {
      x = (rnd() % vmax) + 1;
    }
    long long y;
    if (op == 4) {
      y = (rnd() % vmax) + 1;
    }
    switch (op) {
      case 1:
        it.add(l, r, x);
        break;
      case 2:
        it.set(l, r, x);
        break;
      case 3:
        printf("%I64d\n", it.nth(l, r, x - 1));
        break;
      case 4:
        printf("%I64d\n", it.pw(l, r, x, y));
        break;
    }
  }
  return 0;
}
