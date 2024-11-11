#include <bits/stdc++.h>
using namespace std;
struct st {
  int t, l, r, p;
  bool operator<(const st& B) const { return t < B.t; }
} a[100005];
int N, M, K, s[100005];
vector<st> u[100005], v[100005];
long long b[100005], ans[100005];
int sum(int x) {
  int d = 0;
  for (int i = x; i; i -= i & -i) d += s[i];
  return d;
}
void ins(int x, int d) {
  for (int i = x; i <= M; i += i & -i) s[i] += d;
}
int find(int k) {
  int p = 0;
  for (int i = 20; i >= 0; i--)
    if (p + (1 << i) <= M && s[p + (1 << i)] < k) k -= s[p += 1 << i];
  return p + 1;
}
void init() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++)
    scanf("%d%d%d", &a[i].t, &a[i].l, &a[i].r), b[i] = a[i].t, a[i].p = i;
  sort(a + 1, a + N + 1), sort(b + 1, b + N + 1),
      K = unique(b + 1, b + N + 1) - b - 1;
}
void work(long long t, int p) {
  for (auto i : u[p]) v[i.r].push_back(i), ins(i.r, 1);
  for (auto i : v[p]) ans[i.p] = t;
  ins(p, -u[p].size() - v[p].size());
  u[p].clear(), v[p].clear();
}
void doit() {
  b[++K] = 1e18;
  long long t = 0;
  for (int i = 1, j = 1, p = 1; i <= K; i++) {
    for (; t < b[i];) {
      int n = sum(M), d = sum(p), u = n - sum(p - 1), q;
      if (!n) {
        t = b[i];
        continue;
      }
      if (u >= d) {
        q = find(n - u + 1);
        if (t + q - p <= b[i])
          t += q - p, p = q, work(t, p);
        else
          p += b[i] - t, t = b[i];
      } else {
        q = find(d);
        if (t + p - q <= b[i])
          t += p - q, p = q, work(t, p);
        else
          p -= b[i] - t, t = b[i];
      }
    }
    for (; j <= N && a[j].t == b[i]; j++)
      ins(a[j].l, 1), u[a[j].l].push_back(a[j]);
  }
  for (int i = 1; i <= N; i++) printf("%I64d\n", ans[i]);
}
int main() {
  init();
  doit();
  return 0;
}
