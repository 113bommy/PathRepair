#include <bits/stdc++.h>
int t[2000];
int main() {
  int n, k = 0, P[4], T[3];
  scanf("%d%d%d%d%d%d", &n, &P[1], &P[2], &P[3], &T[1], &T[2]);
  for (int i = 0, l, r; i < n; i++) {
    scanf("%d%d", &l, &r);
    t[k++] = l;
    t[k++] = r;
  }
  int ans = 0;
  for (int i = 0; i + 1 < k; i += 2) {
    ans += P[1] * (t[i + 1] - t[i]);
  }
  for (int i = 1; i + 1 < k - 1; i += 2) {
    int l = t[i + 1] - t[i];
    if (l <= T[1]) {
      ans += P[1] * l;
    } else {
      ans += P[1] * T[1];
      l -= T[1];
      if (l <= T[2]) {
        ans += P[2] * l;
      } else {
        ans += P[2] * T[2];
        l -= T[2];
        ans += P[3] * l;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
