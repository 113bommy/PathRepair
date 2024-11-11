#include <bits/stdc++.h>
using namespace std;
pair<int, int> inp[(int)2e5 + 5];
int k, n, p[(int)2e5 + 5], tree[(int)8e5 + 5];
long long ans;
int update(int i, int t, int nl, int nr) {
  if (i < nl || nr < i) return tree[t];
  if (nl == nr) return tree[t] = 1;
  int m = nl + nr >> 1;
  return tree[t] = update(i, t * 2, nl, m) + update(i, t * 2 + 1, m + 1, nr);
}
int get(int ql, int qr, int t, int nl, int nr) {
  if (qr < ql) return 0;
  if (nr < ql || qr < nl) return 0;
  if (ql <= nl && nr <= qr) return tree[t];
  int m = nl + nr >> 1;
  return get(ql, qr, t * 2, nl, m) + get(ql, qr, t * 2 + 1, m + 1, nr);
}
int f(int x) { return lower_bound(p, p + k, x) - p; }
long long calc(long long x) { return x * (x + 1) >> 1; }
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    inp[i + 1] = {-b, a};
    p[i] = a;
  }
  sort(inp + 1, inp + n + 1);
  sort(p, p + n);
  k = unique(p, p + n) - p;
  for (int i = 1; i <= n; i++) {
    int a = f(inp[i - 1].second), b = f(inp[i].second),
        c = f(inp[i + 1].second);
    update(b, 1, 0, k - 1);
    if (inp[i].first != inp[i + 1].first) {
      ans += calc(get(0, k - 1, 1, 0, k - 1));
      ans -= calc(get(b + 1, k - 1, 1, 0, k - 1));
    }
    if (inp[i - 1].first != inp[i].first) {
      ans -= calc(get(0, b - 1, 1, 0, k - 1));
    } else {
      ans -= calc(get(a + 1, b - 1, 1, 0, k - 1));
    }
  }
  printf("%lld\n", ans);
}
