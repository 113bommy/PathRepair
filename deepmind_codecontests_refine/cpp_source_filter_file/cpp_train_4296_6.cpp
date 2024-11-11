#include <bits/stdc++.h>
using namespace std;
int n, k, i, fa[100002];
bool check(int x) {
  while (x != 1) {
    if (x % 2 != 0) return 0;
    x /= 2;
  }
  return 1;
}
int main() {
  scanf("%d%d", &n, &k);
  if ((n == 9 && k == 2) || n % 2 == 0)
    puts("NO");
  else if (k == 0) {
    if (!check(n + 1))
      puts("NO");
    else {
      puts("YES");
      for (i = 1; i <= n; i++) printf("%d ", i / 2);
      puts("");
    }
  } else if (k == 1) {
    if (check(n + 1))
      puts("NO");
    else {
      puts("YES");
      for (i = 1; i <= n; i++) printf("%d ", i / 2);
      puts("");
    }
  } else {
    int n1 = n - 2 * (k - 1);
    if (n1 <= 1)
      puts("NO");
    else if (!check(n1 + 1)) {
      fa[1] = n1 + k - 1;
      for (i = 2; i <= n1; i++) fa[i] = i / 2;
      for (i = n1 + 2; i <= n1 + k - 1; i++) fa[i] = i - 1;
      for (i = n1 + k; i <= n; i++) fa[i] = i - k + 1;
      puts("YES");
      for (i = 1; i <= n; i++) printf("%d ", fa[i]);
      puts("");
    } else {
      for (i = 2; i <= n1 - 2; i++) fa[i] = i / 2;
      fa[1] = n1 + k - 1;
      for (i = n1 + 2; i <= n1 + k - 1; i++) fa[i] = i - 1;
      for (i = n1 + k; i <= n; i++) fa[i] = i - k + 1;
      fa[n1 - 1] = fa[n1] = n1 + k;
      if (n - 4 < 6 && 2 * (n - 4) > 3)
        puts("NO");
      else {
        puts("YES");
        for (i = 1; i <= n; i++) printf("%d ", fa[i]);
        puts("");
      }
    }
  }
  return 0;
}
