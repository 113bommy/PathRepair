#include <bits/stdc++.h>
using namespace std;
int n, p, l = 100005, r = 0;
char s[100005];
int main() {
  scanf("%d %d\n", &n, &p);
  if (p * 2 > n) p = n + 1 - p;
  for (int i = 0; i < n; i++) scanf("%c", &s[i]);
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 1 - i]) {
      l = min(l, i);
      r = max(r, i);
    }
  }
  if (l == 100005) l = r = 0, p = 1;
  int ans = (r - l) + min(abs(r + 1 - p), abs(l + 1 - p));
  for (int i = 0; i * 2 < n; i++) {
    if (s[i] > s[n - 1 - i]) swap(s[i], s[n - 1 - i]);
    ans += min(s[n - 1 - i] - s[i], s[i] + 26 - s[n - 1 - i]);
  }
  printf("%d\n", ans);
  return 0;
}
