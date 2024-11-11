#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
int n, l, r, ql, qr, a[MAX], s[MAX];
int getAns(int c1, int c2) {
  int ans = 0;
  if (c1 > c2) ans += (c1 - c2 - 1) * ql;
  if (c2 > c1) ans += (c2 - c1 - 1) * qr;
  return ans;
}
int main() {
  scanf("%d%d%d%d%d", &n, &l, &r, &ql, &qr);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  int sol = 1e9;
  for (int i = 1; i <= n; i++) {
    int v1 = s[i] * l + (s[n] - s[i]) * r + getAns(i, n - i);
    int v2 = s[i - 1] * l + (s[n] - s[i - 1]) * r + getAns(i - 1, n - i + 1);
    int v = min(v1, v2);
    if (v < sol) sol = v;
  }
  printf("%d\n", sol);
  return 0;
}
