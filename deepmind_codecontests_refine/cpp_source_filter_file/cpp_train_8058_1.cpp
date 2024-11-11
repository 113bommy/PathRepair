#include <bits/stdc++.h>
using namespace std;
int n, m, a[+100500], l, ans[+100500];
bool used[+100500];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (used[a[i]])
      ans[i] = ans[i + 1];
    else if (!used[a[i]]) {
      ans[i] = ans[i + 1] + 1;
      used[a[i]] = true;
    }
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &l);
    printf("%d\n", ans[l]);
  }
  return 0;
  ;
}
