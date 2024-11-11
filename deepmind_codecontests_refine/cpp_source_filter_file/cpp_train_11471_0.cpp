#include <bits/stdc++.h>
using namespace std;
int a[405];
int ed[405];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    memset(ed, 0, sizeof(ed));
    for (int i = 1; i <= 4 * n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 4 * n + 1);
    int cnt = 1, ok = 0;
    for (int i = 1; i <= 4 * n; i += 2) {
      if (a[i] != a[i + 1]) ok = 1;
      ed[cnt++] = a[i];
    }
    if (ok) {
      printf("NO\n");
      continue;
    }
    ok = 0;
    for (int i = 1; i < cnt - 1; i++) {
      if (ed[i] * ed[cnt - i] == ed[i + 1] * ed[cnt - i - 1])
        ok = 1;
      else {
        ok = 0;
        break;
      }
    }
    if (ok) {
      printf("NO\n");
      continue;
    } else
      printf("NO\n");
  }
}
