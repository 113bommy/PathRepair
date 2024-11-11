#include <bits/stdc++.h>
using namespace std;
int n, i = 1, a[1111111], b[1111111];
char s[1111111];
int main() {
  for (scanf("%d", &n); i <= n; i++) scanf("%s%d%d", s, a + i, b + i);
  for (i = 1; i <= n; i++)
    if (a[i] > 2399 && b[i] > a[i]) return puts("YES"), 0;
  puts("NO");
}
