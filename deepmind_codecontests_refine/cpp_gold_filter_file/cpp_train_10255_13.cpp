#include <bits/stdc++.h>
using namespace std;
int n, a[2015], b[2015], id[2015];
pair<int, int> ans[2000100];
int stk[2000100];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    id[b[i]] = i;
  }
  int tot = 0, ned = 0, top = -1;
  for (int i = 1; i <= n; i++) {
    if (id[a[i]] > i)
      stk[++top] = i;
    else if (id[a[i]] < i) {
      int tmp = i;
      for (int j = top; j >= 0; j--) {
        if (id[a[stk[j]]] > stk[j]) {
          ned += tmp - stk[j];
          swap(a[stk[j]], a[tmp]);
          ans[tot++] = make_pair(stk[j], tmp);
          swap(tmp, stk[j]);
          if (a[tmp] == b[tmp]) break;
        }
      }
    }
  }
  printf("%d\n", ned);
  printf("%d\n", tot);
  for (int i = 0; i < tot; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
