#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ '0');
    ch = getchar();
  }
  return x * f;
}
namespace SegmentTree {
struct node {
  int l, r;
  int val;
  bool tag;
} tree[1000005 << 2];
inline void pushup(const int &i) {
  tree[i].val = (tree[i << 1].val + tree[i << 1 | 1].val) % 1000000007;
}
inline void Change(const int &i, const int &rt) {
  tree[i].val = 0;
  tree[i].tag = true;
}
inline void pushdown(const int &i) {
  if (tree[i].tag) {
    Change(i << 1, i), Change(i << 1 | 1, i);
    tree[i].tag = false;
  }
}
void Build(int l, int r, int i) {
  tree[i].l = l, tree[i].r = r;
  tree[i].tag = 0, tree[i].val = 0;
  if (l == r) {
    return;
  }
  int mid = (l + r) >> 1;
  Build(l, mid, i << 1);
  Build(mid + 1, r, i << 1 | 1);
}
void Cover(int i, int L, int R) {
  if (L <= tree[i].l && tree[i].r <= R) {
    tree[i].tag = true;
    tree[i].val = 0;
    return;
  }
  pushdown(i);
  int mid = (tree[i].l + tree[i].r) >> 1;
  if (L <= mid) Cover(i << 1, L, R);
  if (mid < R) Cover(i << 1 | 1, L, R);
  pushup(i);
}
void Update(int i, int index, int val) {
  if (tree[i].l == tree[i].r) {
    tree[i].val = val;
    return;
  }
  pushdown(i);
  int mid = (tree[i].l + tree[i].r) >> 1;
  if (index <= mid)
    Update(i << 1, index, val);
  else
    Update(i << 1 | 1, index, val);
  pushup(i);
}
int Query(int i, int L, int R) {
  if (L > R) return 0;
  if (L <= tree[i].l && tree[i].r <= R) {
    return tree[i].val;
  }
  pushdown(i);
  int mid = (tree[i].l + tree[i].r) >> 1, ans = 0;
  if (L <= mid) ans = (ans + Query(i << 1, L, R)) % 1000000007;
  if (mid < R) ans = (ans + Query(i << 1 | 1, L, R)) % 1000000007;
  return ans;
}
}  // namespace SegmentTree
using namespace SegmentTree;
struct sgmt {
  int x, y1, y2;
  bool flag;
};
inline bool operator<(const sgmt &A, const sgmt &B) {
  if (A.x != B.x) {
    return A.x < B.x;
  } else {
    if (A.y1 == B.y1) {
      return A.y2 > B.y2;
    } else {
      return A.y1 > B.y1;
    }
  }
}
set<pair<int, int> > now;
sgmt s[1000005 * 2];
int tot;
inline void Add(sgmt A) { s[++tot] = A; }
int main() {
  int n = read(), m = read(), k = read();
  for (register int i = 1; i <= k; ++i) {
    int x1 = read(), y1 = read(), x2 = read(), y2 = read();
    Add(sgmt{x1, y1, y2, 0});
    Add(sgmt{x2 + 1, y1, y2, 1});
  }
  Build(1, m, 1);
  Update(1, 1, 1);
  sort(s + 1, s + 1 + tot);
  int p = 1;
  for (p = 1; s[p].x == 1; ++p) {
    if (s[p].flag == 0) {
      now.insert(make_pair(s[p].y1, s[p].y2));
    }
  }
  now.insert(make_pair(0, 0));
  for (register int i = 2; i <= n; ++i) {
    for (register int j = p; s[j].x == i; ++j) {
      int pos = s[j].y2 + 1;
      if (s[j].flag == 0 && pos <= m) {
        int low = (*--now.lower_bound(make_pair(pos, 0))).second;
        Update(1, pos, Query(1, low + 1, pos));
      }
    }
    for (register int j = p; s[j].x == i; ++j) {
      if (s[j].flag) {
        now.erase(make_pair(s[j].y1, s[j].y2));
      }
    }
    for (register int j = p; s[j].x == i; ++j, ++p) {
      if (!s[j].flag) {
        now.insert(make_pair(s[j].y1, s[j].y2));
        Cover(1, s[j].y1, s[j].y2);
      }
    }
  }
  cout << Query(1, (*(--now.end())).first + 1, m) % 1000000007 << endl;
}
