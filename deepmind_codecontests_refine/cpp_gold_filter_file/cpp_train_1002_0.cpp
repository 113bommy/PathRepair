#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[60];
char s[60];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    long long res = 0;
    for (int j = 1; j <= m; ++j)
      if (s[j] == '#') res += (1ll << j - 1);
    a[i] = res;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1 + i; j <= n; ++j)
      if ((a[i] != a[j]) && (a[i] & a[j])) {
        puts("No");
        return 0;
      }
  puts("Yes");
}
