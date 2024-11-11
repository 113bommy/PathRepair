#include <bits/stdc++.h>
const int maxn = 2e5 + 11;
int n, a;
int cnt = 0;
int m[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    m[a]++;
  }
  for (int i = 1; i <= n; i++) {
    if (!m[i]) cnt++;
  }
  printf("%d", cnt);
  return 0;
}
