#include <bits/stdc++.h>
int val[200001];
long long ta[1 << 22];
long long tb[1 << 22];
int n;
long long a, b;
void update(int i, int l, int r, int x) {
  if (l == r) {
    ta[i] = std::min((long long)val[l], a);
    tb[i] = std::min((long long)val[l], b);
  } else {
    int t = (l + r) >> 1;
    if (x <= t)
      update(2 * i, l, t, x);
    else
      update(2 * i + 1, t + 1, r, x);
    ta[i] = ta[2 * i] + ta[2 * i + 1];
    tb[i] = tb[2 * i] + tb[2 * i + 1];
  }
}
long long sum(int i, int nl, int nr, int ql, int qr, bool f) {
  if (qr < nl || ql > nr || ql > qr) return 0;
  if (ql <= nl && qr >= nr) return f ? ta[i] : tb[i];
  int t = (nl + nr) >> 1;
  long long lv = sum(i * 2, nl, t, ql, qr, f);
  long long rv = sum(i * 2 + 1, t + 1, nr, ql, qr, f);
  return lv + rv;
}
int main() {
  int k, q, x, y;
  scanf("%d%d%I64d%I64d%d", &n, &k, &a, &b, &q);
  while (q--) {
    scanf("%d", &x);
    if (x & 1) {
      scanf("%d%d", &x, &y);
      val[x] = y;
      update(1, 1, n, x);
    } else {
      scanf("%d", &y);
      long long ans = sum(1, 1, n, y + k, n, true);
      ans += sum(1, 1, n, 1, y - 1, false);
      printf("%I64d\n", ans);
    }
  }
}
