#include <bits/stdc++.h>
int a[100001], p[100001], N, Q;
int T[2100001], ls[2100001], rs[2100001], n, root[100001];
int end[100001], steps[100001];
int build(int l, int r) {
  int p = ++n;
  T[p] = r - l + 1;
  if (l < r) {
    int m = l + r >> 1;
    ls[p] = build(l, m);
    rs[p] = build(m + 1, r);
  }
  return p;
}
int get_kth(int p, int x) {
  int l = 1, r = N;
  while (l < r) {
    int m = l + r >> 1;
    if (x <= T[ls[p]])
      p = ls[p], r = m;
    else
      x -= T[ls[p]], p = rs[p], l = m + 1;
  }
  return l;
}
int P(int p, int x, int w) {
  int l = 1, r = N, root;
  T[root = ++n] = T[p] + w;
  while (l < r) {
    int m = l + r >> 1;
    if (x <= m)
      ls[n] = n + 1, rs[n] = rs[p], p = ls[p], r = m;
    else
      rs[n] = n + 1, ls[n] = ls[p], p = rs[p], l = m + 1;
    T[++n] = T[p] + w;
  }
  return root;
}
int G(int p, int x) {
  int l = 1, r = N, ans = 0;
  while (l < r) {
    int m = l + r >> 1;
    if (x <= m)
      p = ls[p], r = m;
    else
      ans += T[ls[p]], p = rs[p], l = m + 1;
  }
  return ans + T[p];
}
int main() {
  scanf("%d%d", &N, &Q);
  for (int i = 1; i <= N; i++) scanf("%d", a + i);
  end[0] = a[1] - 1;
  steps[0] = 0;
  for (int i = 1; i < N; i++) {
    int add = (a[i + 1] - end[i - 1] - 1) / i;
    end[i] = end[i - 1] + i * add;
    steps[i] = steps[i - 1] + add;
  }
  for (int i = 2; i <= N; i++) p[i] = (p[i - 1] + a[i] - a[i - 1]) % (i - 1);
  root[N] = build(1, N);
  for (int i = N; i; i--) {
    p[i] = get_kth(root[i], p[i] + 1);
    root[i - 1] = P(root[i], p[i], -1);
  }
  while (Q--) {
    int x, k;
    scanf("%d%d", &x, &k);
    if (x < a[1]) {
      printf("%d\n", x);
      continue;
    }
    int belong = std::lower_bound(end + 1, end + N, x) - end;
    k += steps[belong - 1] + (x - end[belong - 1] - 1) / belong + 1;
    int ord = (x - end[belong - 1] - 1) % belong + 1;
    ord = get_kth(root[belong], ord);
    belong = std::lower_bound(steps + 1, steps + N, k) - steps;
    printf("%lld\n", end[belong - 1] +
                         (long long)(k - steps[belong - 1] - 1) * belong +
                         G(root[belong], ord));
  }
  return 0;
}
