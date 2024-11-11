#include <bits/stdc++.h>
using namespace std;
int n, m, d;
int c[100005], cnt[22], p[1 << 22];
int get(int st) {
  int ret = 0;
  while (st) {
    st &= st - 1;
    ret++;
  }
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &m, &d);
  int x, y;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &x);
    for (int j = 0; j < x; ++j) {
      scanf("%d", &y);
      c[y - 1] = i;
    }
  }
  int now = 0;
  for (int i = 0; i < n; ++i) {
    cnt[c[i]]++;
    now |= (1 << c[i]);
    if (i - d >= 0) {
      cnt[c[i - d]]--;
      if (cnt[c[i - d]] == 0) {
        now ^= (1 << c[i - d]);
      }
    }
    if (i - d - 1 >= 0) {
      p[(1 << m) - now - 1] = 1;
    }
  }
  for (int st = (1 << m) - 1; st >= 0; --st) {
    for (int i = 0; i < m; ++i) {
      if (st & (1 << i)) {
        p[st ^ (1 << i)] |= p[st];
      }
    }
  }
  int ans = 22;
  for (int i = 0; i < (1 << m); ++i) {
    if (p[i]) continue;
    ans = min(ans, get(i));
  }
  printf("%d\n", ans);
  return 0;
}
