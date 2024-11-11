#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline int chkmin(T &x, const T &y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline int chkmax(T &x, const T &y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline T read(T &f) {
  f = 0;
  int x = 1;
  char c = getchar();
  while (!isdigit(c)) x = c == '-' ? -1 : 1, c = getchar();
  while (isdigit(c)) (f *= 10) += c & 15, c = getchar();
  return f *= x;
}
using int64 = long long;
using uint64 = unsigned long long;
const int N = 1000000 + 5;
int n, q, A[N];
vector<int> G[N], Q[N];
struct Query {
  int l, k;
} qry[N];
int Ans[N];
int cnt[N];
int sum[N << 2];
set<int> buc[N];
void modify(int rt, int l, int r, int p, int v) {
  if (l == r) {
    sum[rt] += 1;
    buc[l].insert(v);
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    modify(rt << 1, l, mid, p, v);
  else
    modify(rt << 1 | 1, mid + 1, r, p, v);
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void modify_1(int rt, int l, int r, int p, int v) {
  if (l == r) {
    sum[rt] -= 1;
    buc[l].erase(v);
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    modify_1(rt << 1, l, mid, p, v);
  else
    modify_1(rt << 1 | 1, mid + 1, r, p, v);
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
int query(int rt, int l, int r, int x, int y) {
  if (l > y || r < x) return 0;
  if (x <= l && r <= y) {
    return sum[rt];
  }
  int mid = (l + r) >> 1, ret = 0;
  if (x <= mid) ret += query(rt << 1, l, mid, x, y);
  if (y > mid) ret += query(rt << 1 | 1, mid + 1, r, x, y);
  return ret;
}
int find(int rt, int l, int r, int x, int y, int k) {
  if (l == r) {
    return *buc[l].begin();
  }
  int mid = (l + r) >> 1, ret = query(rt << 1, l, mid, x, y);
  if (k <= ret)
    return find(rt << 1, l, mid, x, y, k);
  else
    return find(rt << 1 | 1, mid + 1, r, x, y, k - ret);
}
void dfs(int u, int dep) {
  if (cnt[A[u]]) modify_1(1, 1, n, cnt[A[u]], A[u]);
  cnt[A[u]]++;
  modify(1, 1, n, cnt[A[u]], A[u]);
  for (int id : Q[u]) {
    int ret = query(1, 1, n, qry[id].l, n);
    if (ret < qry[id].k) {
      Ans[id] = -1;
    } else {
      Ans[id] = find(1, 1, n, qry[id].l, n, qry[id].k);
    }
  }
  for (int v : G[u]) {
    dfs(v, dep + 1);
  }
  modify_1(1, 1, n, cnt[A[u]], A[u]);
  cnt[A[u]]--;
  if (cnt[A[u]]) modify(1, 1, n, cnt[A[u]], A[u]);
}
void build(int rt, int l, int r) {
  sum[rt] = 0;
  if (l == r) {
    buc[l].clear();
    return;
  }
  int mid = (l + r) >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> q;
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
      cin >> A[i];
      G[i].clear();
      Q[i].clear();
    }
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      G[p].push_back(i);
    }
    for (int i = 1; i <= q; i++) {
      int v, l, k;
      cin >> v >> l >> k;
      Q[v].push_back(i);
      qry[i] = {l, k};
    }
    dfs(1, 0);
    for (int i = 1; i <= q; i++) {
      printf("%d ", Ans[i]);
    }
    puts("");
  }
  return 0;
}
