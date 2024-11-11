#include <bits/stdc++.h>
using namespace std;
const int Maxn = 200005, INF = 1 << 30;
int n, tot, tp[Maxn], f[Maxn], C[Maxn], ans;
struct Line {
  int l, r;
} A[Maxn];
bool cmp(const Line &a, const Line &b) {
  return a.l < b.l || a.l == b.l && a.r < b.r;
}
int Get() {
  char ch;
  int v = 0;
  bool f = false;
  while (!isdigit(ch = getchar()))
    if (ch == '-') f = true;
  v = ch - 48;
  while (isdigit(ch = getchar())) v = v * 10 + ch - 48;
  if (f)
    return -v;
  else
    return v;
}
void modify(int x, int v) {
  for (; x <= tot; x += x & (-x)) C[x] = max(C[x], v);
}
int Query(int x) {
  int res = 0;
  for (; x; x -= x & (-x)) res = max(res, C[x]);
  return res;
}
int main() {
  n = Get();
  int x, w;
  for (int i = 1; i <= n; i++) {
    x = Get(), w = Get();
    A[i].l = x - w, A[i].r = x + w;
    tp[++tot] = A[i].r;
  }
  sort(A + 1, A + 1 + n, cmp);
  sort(tp + 1, tp + 1 + tot);
  tot = unique(tp + 1, tp + 1 + tot) - tp - 1;
  for (int i = 1; i <= n; i++)
    A[i].r = lower_bound(tp + 1, tp + 1 + tot, A[i].r) - tp;
  f[1] = 1, modify(A[1].r, 1);
  ans = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = Query(upper_bound(tp + 1, tp + 1 + tot, A[i].l) - tp - 1) + 1;
    modify(A[i].r, f[i]);
    ans = max(ans, f[i]);
  }
  cout << ans << endl;
  return 0;
}
