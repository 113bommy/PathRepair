#include <bits/stdc++.h>
using namespace std;
const int MX = 200000, INF = 1000000000;
int a[MX], ololo[MX], olololo[MX];
int main() {
  int n, m, last;
  scanf("%d %d %d", &n, &m, &last);
  for (int i = 1; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[i] = abs(x - last);
    last = x;
  }
  a[0] = a[n] = INF;
  ololo[0] = 0;
  for (int i = 1; i < n; i++) {
    int j = i - 1;
    while (a[i] > a[j]) j = ololo[j];
    ololo[i] = j;
  }
  olololo[n] = n;
  for (int i = n - 1; i > 0; i--) {
    int j = i + 1;
    while (a[i] > a[j]) j = olololo[j];
    olololo[i] = j;
  }
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    long long ans = 0;
    for (int i = l; i < r; i++)
      ans += a[i] * 1LL * (min(olololo[i], r) - i) * 1LL *
             (i - max(ololo[i], l - 1));
    printf("%I64d\n", ans);
  }
  return 0;
}
