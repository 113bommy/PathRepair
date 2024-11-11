#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
int q, n;
int a[N], b[N], c[N];
int mi[N][22];
int lg[N];
set<int> st;
int que(int l, int r) {
  int k = lg[r - l + 1];
  return min(mi[l][k], mi[r - (1 << k) + 1][k]);
}
int main() {
  for (int i = 0; i < N; i++) lg[i] = log2(i);
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int mx = unique(b + 1, b + 1 + n) - b - 1;
    st.clear();
    for (int i = 1; i <= mx; i++) c[i] = mx + 1;
    for (int i = 1; i <= n; i++) {
      a[i] = lower_bound(b + 1, b + 1 + mx, a[i]) - b;
      int bg = *st.upper_bound(a[i]);
      if (bg > a[i]) c[a[i]] = min(c[a[i]], bg);
      st.insert(a[i]);
    }
    for (int i = 1; i <= mx; i++) mi[i][0] = c[i];
    for (int j = 1; j <= 20; j++) {
      for (int i = 1; i + (1 << j) - 1 <= mx; i++) {
        mi[i][j] = min(mi[i][j - 1], mi[i + (1 << j - 1) - 1][j - 1]);
      }
    }
    int p = 0, q = 0;
    int ans = n;
    while (p <= mx) {
      while (q < mx) {
        if (que(p + 1, q + 1) > q + 1)
          q++;
        else
          break;
      }
      ans = min(ans, p + mx - q);
      p++;
    }
    printf("%d\n", ans);
  }
}
