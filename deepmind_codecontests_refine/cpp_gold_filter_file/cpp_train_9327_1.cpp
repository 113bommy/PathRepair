#include <bits/stdc++.h>
using namespace std;
struct Node {
  long long lazy, sum, lazy1, lazy2;
} tree[12 * 400005];
struct Q {
  long long type, l, r;
  Q() {}
  Q(long long a, long long b, long long c) : type(a), l(b), r(c) {}
};
vector<Q> que;
vector<long long> t;
long long pre[12 * 400005];
map<long long, long long> ma;
long long n, tot = 0, ans = 0;
void input() {
  scanf("%I64d", &n);
  for (long long i = 0; i < n; i++) {
    long long a, b, c;
    scanf("%I64d%I64d%I64d", &a, &b, &c);
    que.push_back(Q(a, b, c));
    t.push_back(c), t.push_back(max(1LL, c - 1)), t.push_back(c + 1);
    t.push_back(b), t.push_back(max(1LL, b - 1)), t.push_back(b + 1);
  }
  t.push_back(1);
  sort(t.begin(), t.end());
  t.erase(unique(t.begin(), t.end()), t.end());
  for (long long i = 0; i < t.size(); i++) {
    ma[t[i]] = ++tot;
    pre[tot] = t[i];
  }
}
void pushup(long long root, long long l, long long r) {
  tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;
}
void pushdown(long long root, long long l, long long r) {
  if (tree[root].lazy == 1) {
    tree[root].lazy = 0;
    tree[root * 2].lazy1 = 0, tree[root * 2 + 1].lazy1 = 0;
    tree[root * 2].lazy2 = 0, tree[root * 2 + 1].lazy2 = 0;
    tree[root * 2].lazy = 1, tree[root * 2 + 1].lazy = 1;
    tree[root * 2].sum = 0, tree[root * 2 + 1].sum = 0;
  }
  if (tree[root].lazy1 == 1) {
    tree[root].lazy1 = 0;
    tree[root * 2].lazy = 0, tree[root * 2 + 1].lazy = 0;
    tree[root * 2].lazy2 = 0, tree[root * 2 + 1].lazy2 = 0;
    tree[root * 2].lazy1 = 1, tree[root * 2 + 1].lazy1 = 1;
    long long mid = (l + r) / 2;
    tree[root * 2].sum = mid - l + 1;
    tree[root * 2 + 1].sum = r - mid;
  }
  if (tree[root].lazy2 == 1) {
    tree[root].lazy2 = 0;
    long long mid = (l + r) / 2;
    if (tree[root * 2].lazy == 1) {
      tree[root * 2].lazy = 0;
      tree[root * 2].lazy1 = 1;
      tree[root * 2].sum = mid - l + 1;
    } else if (tree[root * 2].lazy1 == 1) {
      tree[root * 2].lazy1 = 0;
      tree[root * 2].lazy = 1;
      tree[root * 2].sum = 0;
    } else if (tree[root * 2].lazy2 == 1) {
      tree[root * 2].lazy2 = 0;
      tree[root * 2].sum = (mid - l + 1) - tree[root * 2].sum;
    } else if (tree[root * 2].lazy2 == 0) {
      tree[root * 2].lazy2 = 1;
      tree[root * 2].sum = (mid - l + 1) - tree[root * 2].sum;
    }
    if (tree[root * 2 + 1].lazy == 1) {
      tree[root * 2 + 1].lazy = 0;
      tree[root * 2 + 1].lazy1 = 1;
      tree[root * 2 + 1].sum = r - mid;
    } else if (tree[root * 2 + 1].lazy1 == 1) {
      tree[root * 2 + 1].lazy1 = 0;
      tree[root * 2 + 1].lazy = 1;
      tree[root * 2 + 1].sum = 0;
    } else if (tree[root * 2 + 1].lazy2 == 1) {
      tree[root * 2 + 1].lazy2 = 0;
      tree[root * 2 + 1].sum = (r - mid) - tree[root * 2 + 1].sum;
    } else if (tree[root * 2 + 1].lazy2 == 0) {
      tree[root * 2 + 1].lazy2 = 1;
      tree[root * 2 + 1].sum = (r - mid) - tree[root * 2 + 1].sum;
    }
  }
  return;
}
void build(long long root, long long l, long long r) {
  tree[root].lazy = 0, tree[root].lazy1 = 0, tree[root].lazy2 = 0;
  tree[root].sum = 0;
  if (l == r) {
    tree[root].lazy = 0, tree[root].sum = 1, tree[root].lazy1 = 0,
    tree[root].lazy2 = 0;
    return;
  }
  long long mid = (l + r) / 2;
  build(root * 2, l, mid);
  build(root * 2 + 1, mid + 1, r);
  pushup(root, l, r);
}
void update(long long root, long long l, long long r, long long p, long long q,
            long long type) {
  if (p <= l && q >= r) {
    if (type == 1) {
      tree[root].lazy2 = 0, tree[root].lazy1 = 0;
      tree[root].lazy = 1;
      tree[root].sum = 0;
      pushdown(root, l, r);
    } else if (type == 2) {
      tree[root].lazy = 0, tree[root].lazy2 = 0;
      tree[root].lazy1 = 1;
      tree[root].sum = (r - l + 1);
      pushdown(root, l, r);
    } else if (type == 3) {
      if (tree[root].lazy == 1) {
        tree[root].lazy = 0;
        tree[root].lazy1 = 1;
        tree[root].sum = (r - l + 1);
        pushdown(root, l, r);
        return;
      } else if (tree[root].lazy1 == 1) {
        tree[root].lazy1 = 0;
        tree[root].lazy = 1;
        tree[root].sum = 0;
        pushdown(root, l, r);
        return;
      } else if (tree[root].lazy2 == 1) {
        tree[root].lazy2 = 0;
        tree[root].sum = (r - l + 1) - tree[root].sum;
      } else if (tree[root].lazy2 == 0) {
        tree[root].lazy2 = 1;
        tree[root].sum = (r - l + 1) - tree[root].sum;
        pushdown(root, l, r);
      }
    }
    return;
  } else {
    pushdown(root, l, r);
    long long mid = (l + r) / 2;
    if (p <= mid) update(root * 2, l, mid, p, q, type);
    if (q > mid) update(root * 2 + 1, mid + 1, r, p, q, type);
    pushup(root, l, r);
  }
}
void query(long long root, long long l, long long r) {
  if (l == r) {
    ans = pre[l];
    tree[root].lazy = tree[root].lazy1 = tree[root].lazy2 = 0;
    return;
  }
  long long mid = (l + r) / 2;
  pushdown(root, l, r);
  if (tree[root * 2].sum > 0) {
    query(root * 2, l, mid);
  } else {
    query(root * 2 + 1, mid + 1, r);
  }
  pushup(root, l, r);
}
void show(long long rt, long long l, long long r) {
  cout << "rt:" << rt << " l:" << l << " r:" << r << " data:" << tree[rt].sum
       << " lazy:" << tree[rt].lazy << " lazy1 :" << tree[rt].lazy1
       << " lazy2 :" << tree[rt].lazy2 << endl;
  if (l == r) return;
  long long md = (l + r) >> 1;
  show(rt * 2, l, md);
  show(rt * 2 + 1, md + 1, r);
}
void solve() {
  for (long long i = 0; i < que.size(); i++) {
    long long l = ma[que[i].l], r = ma[que[i].r];
    update(1, 1, tot, l, r, que[i].type);
    query(1, 1, tot);
    printf("%I64d\n", ans);
  }
}
int main() {
  input();
  build(1, 1, tot);
  solve();
  return 0;
}
