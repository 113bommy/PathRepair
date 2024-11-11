#include <bits/stdc++.h>
using namespace std;
int n, m, sh[100005];
long long ans = 0;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    char ch = getchar();
    while (ch < 'a' || ch > 'z') ch = getchar();
    sh[i] = ch - 'a' + 1;
    if (sh[i] != sh[i - 1]) ans += n * (m - 1);
  }
  int len = 1;
  for (int i = 2; i <= n; i++) {
    if (len == 1) {
      if (sh[i] != sh[i - 1]) len++;
      continue;
    }
    if (sh[i] == sh[i - 2]) {
      len++;
    } else {
      ans -= (len * (len - 1) / 2);
      len = 1;
      if (sh[i] != sh[i - 1]) len++;
    }
  }
  printf("%lld", ans - (len * (len - 1) / 2));
}
