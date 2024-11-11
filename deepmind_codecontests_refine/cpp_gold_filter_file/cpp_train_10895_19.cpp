#include <bits/stdc++.h>
using namespace std;
int i, j = 1, k, n, q, ans[100500], a[100500], num, v[25];
struct sb {
  int l, x, id;
  bool operator<(const sb a) const { return l < a.l; }
} s[100500];
long long ksm(long long a, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) {
      res = res * a % 1000000007;
    }
    a = a * a % 1000000007;
    p >>= 1;
  }
  return res;
}
void add(int k) {
  for (int i = 20; i >= 1; i--) {
    if (k & (1 << (i - 1))) {
      if (!v[i]) {
        v[i] = k;
        num++;
        return;
      }
      k ^= v[i];
    }
  }
}
int main() {
  scanf("%d%d", &n, &q);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 1; i <= q; i++) {
    scanf("%d%d", &s[i].l, &s[i].x);
    s[i].id = i;
  }
  sort(s + 1, s + q + 1);
  for (i = 1; i <= q; i++) {
    for (; j <= s[i].l; j++) {
      add(a[j]);
    }
    for (k = 20; k >= 1; k--) {
      if (s[i].x & (1 << (k - 1))) {
        s[i].x ^= v[k];
      }
    }
    if (!s[i].x) {
      ans[s[i].id] = ksm(2, s[i].l - num);
    }
  }
  for (i = 1; i <= q; i++) {
    printf("%d\n", ans[i]);
  }
}
