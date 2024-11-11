#include <bits/stdc++.h>
inline unsigned int getuint() {
  char w = getchar();
  while (w < '0' || '9' < w) w = getchar();
  unsigned int ans = 0;
  for (; '0' <= w && w <= '9'; w = getchar()) ans = ans * 10 + w - '0';
  return ans;
}
bool ok(int n, int m) {
  static int a[233];
  int len = 0;
  for (; n; n /= m) a[len++] = n % m;
  for (int i = 0; i <= len; i++) {
    if (!a[i] && a[i] != 1 && a[i] != m - 1 && a[i] != m) return false;
    if (a[i] >= m - 1) a[i + 1]++;
  }
  return true;
}
int main() {
  int m = getuint(), n = getuint();
  puts(ok(n, m) ? "YES" : "NO");
  return 0;
}
