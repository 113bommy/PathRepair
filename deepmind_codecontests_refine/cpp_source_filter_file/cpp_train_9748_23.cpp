#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
long long s[maxn << 2], tag[maxn << 2], f[maxn], A[maxn], B[maxn];
vector<int> C[maxn], D[maxn];
vector<int>::iterator ci, di;
int n, m, q;
struct heap {
  priority_queue<long long, vector<long long>, greater<long long> > p1, p2;
  inline void erase(long long x) { p2.push(x); }
  inline void push(long long x) { p1.push(x); }
  inline long long top() {
    while (!p2.empty() && p1.top() == p2.top()) p1.pop(), p2.pop();
    return p1.top();
  }
} p;
void build(int l, int r, int x) {
  if (l == r) {
    s[x] = B[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, x << 1), build(mid + 1, r, x << 1 | 1);
  s[x] = min(s[x << 1], s[x << 1 | 1]);
}
void updata(int l, int r, int x, int a, int b, int c) {
  if (a <= l && r <= b) {
    s[x] += c, tag[x] += c;
    return;
  }
  if (tag[x])
    s[x << 1] += tag[x], s[x << 1 | 1] += tag[x], tag[x << 1] += tag[x],
        tag[x << 1 | 1] += tag[x], tag[x] = 0;
  int mid = (l + r) >> 1;
  if (a <= mid) updata(l, mid, x << 1, a, b, c);
  if (b > mid) updata(mid + 1, r, x << 1 | 1, a, b, c);
  s[x] = min(s[x << 1], s[x << 1 | 1]);
}
inline int rd() {
  int ret = 0, f = 1;
  char gc = getchar();
  while (gc < '0' || gc > '9') {
    if (gc == '-') f = -f;
    gc = getchar();
  }
  while (gc >= '0' && gc <= '9') ret = ret * 10 + (gc ^ '0'), gc = getchar();
  return ret * f;
}
int main() {
  n = rd(), m = rd(), q = rd();
  int i, a;
  for (i = 1; i < n; i++) A[i] = rd(), B[i + 1] = rd();
  for (i = 1; i <= m; i++) a = rd(), C[a].push_back(rd()), D[a].push_back(rd());
  build(1, n, 1);
  for (i = 1; i <= n; i++) {
    for (ci = C[i].begin(), di = D[i].begin(); ci != C[i].end(); ci++, di++)
      updata(1, n, 1, 1, *ci, *di);
    f[i] = s[1], p.push(A[i] + f[i]);
  }
  printf("%I64d\n", p.top());
  for (i = 1; i <= q; i++) {
    a = rd(), p.erase(A[a] + f[a]), f[a] = rd(), p.push(A[a] + f[a]);
    printf("%I64d\n", p.top());
  }
  return 0;
}
