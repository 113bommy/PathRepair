#include <bits/stdc++.h>
using namespace std;
int n, ans[6010], cnt;
char s[2002], t[2002];
inline void rev(int x) {
  if (!x) return;
  reverse(s, s + n);
  reverse(s + x, s + n);
  ans[++cnt] = x;
}
int main() {
  int op = 0, r;
  scanf("%d%s%s", &n, s, t);
  for (int i = 0; i < n; ++i) {
    r = 0;
    while (s[r] != t[i] && r < n) {
      r++;
    }
    if (r >= n - i) {
      printf("-1\n");
      return 0;
    }
    rev(n - r - 1);
    rev(1);
    rev(n - 1);
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; ++i) printf("%d ", ans[i]);
}
