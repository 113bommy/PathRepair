#include <bits/stdc++.h>
struct node {
  long long pos;
  int p;
} p[400005];
bool operator<(const node &a, const node &b) {
  if (a.pos != b.pos) return a.pos < b.pos;
  return a.p > b.p;
}
long long ans[200005];
int main() {
  int n, tot = 0;
  long long x, y;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d %I64d", &x, &y);
    p[++tot] = (node){x, 1};
    p[++tot] = (node){y + 1, -1};
  }
  std::sort(p + 1, p + 1 + tot);
  int now = 0, last = 0;
  for (int i = 1; i <= tot; ++i) {
    ans[now] += p[i].pos - p[i - 1].pos;
    now += p[i].p;
  }
  for (int i = 1; i <= n; ++i) printf("%I64d ", ans[i]);
}
