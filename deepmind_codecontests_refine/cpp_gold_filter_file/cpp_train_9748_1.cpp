#include <bits/stdc++.h>
using namespace std;
template <typename T>
T Max(const T &x, const T &y) {
  return x < y ? y : x;
}
template <typename T>
T Min(const T &x, const T &y) {
  return x < y ? x : y;
}
template <typename T>
int chkmax(T &x, const T &y) {
  return x < y ? (x = y, 1) : 0;
}
template <typename T>
int chkmin(T &x, const T &y) {
  return x > y ? (x = y, 1) : 0;
}
template <typename T>
void read(T &x) {
  T f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (x = 0; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  x *= f;
}
const int maxn = 200010, inf = 0x7fffffff;
struct edge {
  int to, nxt, size;
} e[maxn];
struct Segment {
  int L[maxn << 2], R[maxn << 2], add[maxn << 2], min[maxn << 2];
  void Build(int x, int *a, int l, int r) {
    add[x] = 0;
    if ((L[x] = l) == (R[x] = r)) return min[x] = a[l], void();
    int mid = (l + r) >> 1;
    Build(x << 1, a, l, mid);
    Build(x << 1 | 1, a, mid + 1, r);
    min[x] = Min(min[x << 1], min[x << 1 | 1]);
  }
  void pushadd(int x, int val) {
    add[x] += val;
    min[x] += val;
  }
  void pushdown(int x) {
    if (add[x]) {
      pushadd(x << 1, add[x]);
      pushadd(x << 1 | 1, add[x]);
      add[x] = 0;
    }
  }
  void Add(int x, int l, int r, int val) {
    if (L[x] >= l && R[x] <= r) return pushadd(x, val), void();
    int mid = (L[x] + R[x]) >> 1;
    pushdown(x);
    if (l <= mid) Add(x << 1, l, r, val);
    if (r > mid) Add(x << 1 | 1, l, r, val);
    min[x] = Min(min[x << 1], min[x << 1 | 1]);
  }
  int Qmin(int x, int l, int r) {
    if (L[x] >= l && R[x] <= r) return min[x];
    int mid = (L[x] + R[x]) >> 1;
    pushdown(x);
    if (l <= mid && r > mid)
      return Min(Qmin(x << 1, l, r), Qmin(x << 1 | 1, l, r));
    else if (l <= mid)
      return Qmin(x << 1, l, r);
    else
      return Qmin(x << 1 | 1, l, r);
  }
} t;
struct Segment_Tree {
  int L[maxn << 2], R[maxn << 2], max[maxn << 2], tot[maxn << 2];
  void update(int x) {
    int come = tot[x << 1] - max[x << 1];
    if (come < max[x << 1 | 1])
      tot[x] = max[x] = max[x << 1] + come;
    else if (come < tot[x << 1 | 1]) {
      max[x] = max[x << 1] + max[x << 1 | 1];
      tot[x] = max[x << 1] + come;
    } else {
      max[x] = max[x << 1] + max[x << 1 | 1];
      tot[x] = max[x << 1] + tot[x << 1 | 1];
    }
  }
  void Build(int x, int *a, int *out, int l, int r) {
    if ((L[x] = l) == (R[x] = r)) {
      max[x] = out[l];
      tot[x] = out[l] + a[l];
      return;
    }
    int mid = (l + r) >> 1;
    Build(x << 1, a, out, l, mid);
    Build(x << 1 | 1, a, out, mid + 1, r);
    update(x);
  }
  void Modify(int x, int pos, int ori, int val) {
    if (L[x] == R[x]) return tot[x] += val - ori, void();
    int mid = (L[x] + R[x]) >> 1;
    if (pos <= mid)
      Modify(x << 1, pos, ori, val);
    else
      Modify(x << 1 | 1, pos, ori, val);
    update(x);
  }
} tree;
int n, m, q, num, head[maxn], a[maxn], b[maxn], out[maxn];
pair<int, int> sta[maxn];
void addedge(int u, int v, int w) {
  e[++num].to = v;
  e[num].size = w;
  e[num].nxt = head[u];
  head[u] = num;
}
int main() {
  read(n);
  read(m);
  read(q);
  for (int i = (1), iend = (n - 1); i <= iend; ++i) read(a[i]), read(b[i]);
  a[n] = b[n] = inf;
  t.Build(1, b, 1, n);
  for (int i = (1), iend = (m); i <= iend; ++i) {
    int u, v, w;
    read(u);
    read(v);
    read(w);
    addedge(u, n + v, w);
  }
  int top, flow;
  for (int x = (1), xend = (n); x <= xend; ++x) {
    top = 0;
    for (int i = head[x]; i; i = e[i].nxt)
      sta[++top] = make_pair(e[i].to - n, e[i].size);
    sort(sta + 1, sta + top + 1);
    for (int i = (top), iend = (1); i >= iend; --i) {
      flow = Min(t.Qmin(1, sta[i].first, n), sta[i].second);
      if (flow) {
        t.Add(1, sta[i].first, n, -flow);
        out[x] += flow;
      } else
        break;
    }
  }
  tree.Build(1, a, out, 1, n);
  printf("%d\n", tree.max[1]);
  while (q--) {
    int x, val;
    read(x);
    read(val);
    tree.Modify(1, x, a[x], val);
    printf("%d\n", tree.max[1]);
    a[x] = val;
  }
  return 0;
}
