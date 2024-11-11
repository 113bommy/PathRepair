#include <bits/stdc++.h>
char c;
int i, n, ans[1000010], x[1000010], y[1000010], z;
int IN() {
  for (z = 0; '0' <= (c = getchar()) && c <= '9'; z = z * 10 + c - '0')
    ;
  return z;
}
bool cmp(int a, int b) { return x[a] != x[b] ? x[a] < x[b] : y[a] > y[b]; }
int main() {
  for (n = IN(), i = 0; i < n; ++i)
    y[i] = (x[ans[i] = i] = IN() / 1000) & 1 ? IN() : -IN();
  std::sort(ans, ans + n, cmp);
  for (i = 0; i < n; printf("%d ", ans[i++] + 1))
    ;
  return 0;
}
