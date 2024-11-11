#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1000005;
int read() {
  int s = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * f;
}
set<int> S;
int n, m, Max;
int a[N], b[N], c[N], Ans[N];
bool cmp(int x, int y) { return a[x] < a[y]; }
struct Tree {
  int L, R, l, r, ans, f;
  void Clear() { l = r = L = R = ans = f = 0; }
  void Init(int x) {
    L = R = ans = f = 1;
    l = r = x;
  }
  friend Tree operator+(Tree A, Tree B) {
    Tree C;
    C.Clear();
    C.ans = max(A.ans, B.ans);
    C.l = A.l;
    C.r = B.r;
    if (A.r != B.l) {
      C.f = (A.f & B.f);
      C.ans = max(C.ans, A.R + B.L);
      C.L = (A.f ? A.L + B.L : A.L);
      C.R = (B.f ? B.R + A.R : B.R);
    } else {
      C.L = A.L;
      C.R = B.R;
      C.f = 0;
    }
    return C;
  }
};
struct Segment_Tree {
  Tree t[N * 4];
  void Build(int p, int l, int r) {
    if (l == r) {
      t[p].Init(0);
      return;
    }
    int mid = (l + r) >> 1;
    Build(p << 1, l, mid);
    Build(p << 1 | 1, mid + 1, r);
    t[p] = t[p << 1] + t[p << 1 | 1];
  }
  void Update(int x, int p, int l, int r) {
    if (x < l || x > r) return;
    if (l == r) {
      t[p].Init(1);
      return;
    }
    int mid = (l + r) >> 1;
    Update(x, p << 1, l, mid);
    Update(x, p << 1 | 1, mid + 1, r);
    t[p] = t[p << 1] + t[p << 1 | 1];
  }
  Tree Query1(int x, int p, int l, int r) {
    if (l == r) return t[p];
    int mid = (l + r) >> 1;
    if (x <= mid) return Query1(x, p << 1, l, mid);
    return t[p << 1] + Query1(x, p << 1 | 1, mid + 1, r);
  }
  Tree Query2(int x, int p, int l, int r) {
    if (l == r) return t[p];
    int mid = (l + r) >> 1;
    if (x > mid) return Query2(x, p << 1 | 1, mid + 1, r);
    return Query2(x, p << 1, l, mid) + t[p << 1 | 1];
  }
} tree;
void Solve(int l, int r, int x) {
  if (S.empty()) return;
  set<int>::iterator pos = S.lower_bound(l);
  while (pos != S.end()) {
    if ((*pos) <= r) {
      set<int>::iterator tmp = pos;
      pos++;
      Ans[*tmp] = x;
      S.erase(tmp);
    } else
      break;
  }
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) b[i] = i;
  for (int i = 1; i <= n; i++) S.insert(i);
  sort(b + 1, b + n + 1, cmp);
  tree.Build(1, 1, n);
  for (int i = n; i >= 1; i--) {
    tree.Update(b[i], 1, 1, n);
    c[b[i]] = 1;
    if (a[b[i]] != a[b[i - 1]]) Max = max(Max, (tree.t[1].ans - 1) / 2);
    Tree L = tree.Query1(b[i], 1, 1, n);
    Tree R = tree.Query2(b[i], 1, 1, n);
    int l = b[i] - L.R + 1, r = b[i] + R.L - 1, len = r - l + 1;
    if (c[l] == 0 && c[r] == 0) continue;
    if (c[l] == 1 && c[r] == 1) Solve(l - 1, r + 1, a[b[i]]);
    if (c[l] == 0 && c[r] == 1) Solve(l + len / 2, r + 1, a[b[i]]);
    if (c[l] == 1 && c[r] == 0) Solve(l - 1, r - len / 2, a[b[i]]);
    if (b[i] == l && b[i] != 1) {
      Tree tmp = tree.Query1(b[i] - 1, 1, 1, n);
      int l = b[i] - tmp.R, len = b[i] - l;
      if (c[l] == 1) Solve(l - 1, b[i], a[b[i]]);
      if (c[l] == 0) Solve(l + len / 2, b[i], a[b[i]]);
    }
    if (b[i] == r && b[i] != n) {
      Tree tmp = tree.Query2(b[i + 1], 1, 1, n);
      int r = b[i] + tmp.L, len = r - b[i];
      if (c[r] == 1) Solve(b[i], r + 1, a[b[i]]);
      if (c[r] == 1) Solve(b[i], r - len / 2, a[b[i]]);
    }
  }
  printf("%d\n", Max);
  for (int i = 1; i <= n; i++) printf("%d ", Ans[i]);
  return 0;
}
