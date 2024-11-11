#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 50;
int n;
struct Btree {
  long long num, tag;
  int cmx, cmi;
  long long mi;
  int left, right;
} tree[MAXN * 4];
void _clean(int x) {
  if (tree[x].left == tree[x].right) return;
  if (tree[x].tag == 0) return;
  long long tag = tree[x].tag;
  tree[x].tag = 0;
  tree[x * 2].tag += tag;
  tree[x * 2 + 1].tag += tag;
  tree[x * 2].num += tag;
  tree[x * 2 + 1].num += tag;
}
void _merge(int x) {
  if (tree[x].left == tree[x].right) return;
  tree[x].cmx = tree[x * 2].cmx + tree[x * 2 + 1].cmx;
  tree[x].cmi = max(tree[x * 2].cmi, tree[x * 2 + 1].cmi);
  tree[x].mi = min(tree[x * 2].mi, tree[x * 2 + 1].mi);
}
long long query(int x, int p) {
  _clean(x);
  if (tree[x].left == tree[x].right) {
    return tree[x].num;
  } else {
    int mid = (tree[x].left + tree[x].right) / 2;
    if (p <= mid) return query(x * 2, p);
    return query(x * 2 + 1, p);
  }
}
void _build(int x, int left, int right) {
  tree[x].left = left;
  tree[x].right = right;
  tree[x].tag = tree[x].num = 0;
  if (left == right) {
    scanf("%lld", &tree[x].num);
  } else {
    int mid = (left + right) / 2;
    _build(x * 2, left, mid);
    _build(x * 2 + 1, mid + 1, right);
  }
}
void _modify(int x, int left, int right, long long v) {
  _clean(x);
  if (left <= tree[x].left && tree[x].right <= right) {
    tree[x].tag += v;
    tree[x].num += v;
  } else {
    int mid = (tree[x].left + tree[x].right) / 2;
    if (left <= mid) _modify(x * 2, left, right, v);
    if (mid + 1 <= right) _modify(x * 2 + 1, left, right, v);
  }
}
void _update(int x, int p) {
  _clean(x);
  if (tree[x].left == tree[x].right) {
    long long prev = query(1, p - 1), next = query(1, p + 1);
    if (next < prev) swap(next, prev);
    long long now = tree[x].num;
    tree[x].mi = abs(next - now);
    tree[x].cmx = (now >= prev) && (now >= next);
    if ((now < prev) && (now < next))
      tree[x].cmi = p;
    else
      tree[x].cmi = 0;
  } else {
    int mid = (tree[x].left + tree[x].right) / 2;
    if (p <= mid)
      _update(x * 2, p);
    else
      _update(x * 2 + 1, p);
    _merge(x);
  }
}
int queryMX(int x, int left, int right) {
  _clean(x);
  if (left <= tree[x].left && tree[x].right <= right) {
    return tree[x].cmx;
  } else {
    int ret = 0;
    int mid = (tree[x].left + tree[x].right) / 2;
    if (left <= mid) ret += queryMX(x * 2, left, right);
    if (mid + 1 <= right) ret += queryMX(x * 2 + 1, left, right);
    return ret;
  }
}
int queryMI(int x, int left, int right) {
  _clean(x);
  if (left <= tree[x].left && tree[x].right <= right) {
    return tree[x].cmi;
  } else {
    int ret = 0;
    int mid = (tree[x].left + tree[x].right) / 2;
    if (left <= mid) ret = max(ret, queryMI(x * 2, left, right));
    if (mid + 1 <= right) ret = max(ret, queryMI(x * 2 + 1, left, right));
    return ret;
  }
}
long long queryX(int x, int left, int right) {
  _clean(x);
  if (left <= tree[x].left && tree[x].right <= right) {
    return tree[x].mi;
  } else {
    long long ret = 2100000000;
    int mid = (tree[x].left + tree[x].right) / 2;
    if (left <= mid) ret = min(ret, queryX(x * 2, left, right));
    if (mid + 1 <= right) ret = min(ret, queryX(x * 2 + 1, left, right));
    return ret;
  }
}
long long build(int n) {
  _build(1, 1, n);
  long long ret = 0;
  for (int i = 2; i <= n - 1; i++) _update(1, i);
  for (int i = 2; i <= n; i++) ret += abs(query(1, i) - query(1, i - 1));
  return ret;
}
long long modify(int l, int r, long long v) {
  long long ret = 0;
  if (l > 1) ret -= abs(query(1, l) - query(1, l - 1));
  if (r < n) ret -= abs(query(1, r) - query(1, r + 1));
  _modify(1, l, r, v);
  if (l > 1) {
    _update(1, l);
    ret += abs(query(1, l) - query(1, l - 1));
  }
  if (r < n) {
    _update(1, r);
    ret += abs(query(1, r) - query(1, r + 1));
  }
  if (l - 1 > 1) _update(1, l - 1);
  if (r + 1 < n) _update(1, r + 1);
  return ret;
}
long long query(int l, int r, long long x) {
  if (queryMX(1, l, r) != 0) return 2LL * x;
  long long ret = 0;
  if (l > 1) {
    long long a = query(1, l), b = query(1, l - 1);
    ret = ret - abs(a - b) + abs(a + x - b);
  }
  if (l < n) {
    long long a = query(1, l), b = query(1, l + 1);
    ret = ret - abs(a - b) + abs(a + x - b);
  }
  int ll = max(2, l), rr = min(n - 1, r);
  if (ll <= rr) {
    int mp = queryMI(1, ll, rr);
    if (mp == 0)
      ret = max(ret, 2LL * max(0LL, x - queryX(1, ll, rr)));
    else {
      if (ll <= mp - 1)
        ret = max(ret, 2LL * max(0LL, x - queryX(1, ll, mp - 1)));
      if (mp + 1 <= rr)
        ret = max(ret, 2LL * max(0LL, x - queryX(1, mp + 1, rr)));
      if (mp > 1 && mp < n) {
        long long lmp = query(1, mp - 1), rmp = query(1, mp + 1),
                  nmp = query(1, mp);
        if (rmp < lmp) swap(rmp, lmp);
        ret =
            max(ret, 2LL * max(0LL, x - (lmp - nmp)) - 2LL * min(lmp - nmp, x));
      }
    }
  }
  if (l == 1) {
    long long a = query(1, 1), b = query(1, 2);
    ret = max(ret, abs(a + x - b) - abs(a - b));
  }
  if (r == n) {
    long long a = query(1, n), b = query(1, n - 1);
    ret = max(ret, abs(a + x - b) - abs(a - b));
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  long long ans = build(n);
  int m;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int p, l, r, x;
    scanf("%d %d %d %d", &p, &l, &r, &x);
    if (p == 2) {
      ans += modify(l, r, x);
    } else {
      printf("%lld\n", ans + query(l, r, x));
    }
  }
  return 0;
}
