#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node {
  long long cnt;
  vector<pair<int, int>> st, ed;
} t[N << 1];
int n, m, x;
int a[N];
node merge(node a, node b) {
  if (!a.ed.size()) return b;
  if (!b.ed.size()) return a;
  node ret;
  ret.cnt = a.cnt + b.cnt;
  long long tot = 0;
  for (auto &i : a.ed) {
    for (auto &j : b.st) {
      if (((i.first | j.first) >= x)) {
        tot += (1ll * i.second * j.second);
      }
    }
  }
  ret.cnt += tot;
  ret.st = a.st;
  int tmp;
  tmp = ret.st.back().first;
  for (auto &i : b.st) {
    if (((i.first | tmp) == tmp)) {
      ret.st.back().second += i.second;
    } else {
      ret.st.push_back({i.first | tmp, i.second});
      tmp |= i.first;
    }
  }
  ret.ed = b.ed;
  tmp = ret.ed.back().first;
  for (auto &i : a.ed) {
    if ((i.first | tmp) == tmp) {
      ret.ed.back().second += i.second;
    } else {
      ret.ed.push_back({i.first | tmp, i.second});
      tmp |= i.first;
    }
  }
  return ret;
}
void pushup(int x) { t[x] = merge(t[x << 1], t[x << 1 | 1]); }
void build(int now, int l, int r) {
  if (l == r) {
    t[now].ed.push_back({a[l], 1});
    t[now].st.push_back({a[l], 1});
    if (a[l] >= x) {
      t[now].cnt = 1;
    } else
      t[now].cnt = 0;
    return;
  }
  int mid = (l + r) >> 1;
  build(now << 1, l, mid);
  build(now << 1 | 1, mid + 1, r);
  pushup(now);
}
void modify(int now, int l, int r, int y, int z) {
  if (l == r) {
    a[y] = z;
    t[now].st.clear();
    t[now].ed.clear();
    t[now].st.push_back({z, 1});
    t[now].ed.push_back({z, 1});
    if (a[l] >= x) {
      t[now].cnt = 1;
    } else
      t[now].cnt = 0;
    return;
  }
  int mid = (l + r) >> 1;
  if (y <= mid) {
    modify(now << 1, l, mid, y, z);
  } else
    modify(now << 1 | 1, mid + 1, r, y, z);
  pushup(now);
}
node query(int now, int l, int r, int L, int R) {
  if (L <= l && r <= R) {
    return t[now];
  }
  node ret;
  int mid = (l + r) >> 1;
  if (L <= mid) ret = merge(ret, query(now << 1, l, mid, L, R));
  if (R > mid) ret = merge(ret, query(now << 1 | 1, mid + 1, r, L, R));
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &m, &x);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  build(1, 1, n);
  for (int i = 1; i <= m; ++i) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      int x, y;
      scanf("%d%d", &x, &y);
      a[x] = y;
      modify(1, 1, n, x, y);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%lld\n", query(1, 1, n, l, r).cnt);
    }
  }
  return 0;
}
