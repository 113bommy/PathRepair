#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, ans, a[N], b[N];
bool col[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) col[a[i]] = true;
  col[n + 1] = true;
  bool flag = col[b[n] + 1];
  for (int i = n - b[n] + 1; i <= n; i++)
    if (b[i] != i - n + b[n]) flag = false;
  if (flag) {
    bool t = true;
    for (int i = 1; i <= i - b[n]; i++) {
      if (!col[b[n] + i]) {
        t = false;
        break;
      }
      col[b[i]] = true;
    }
    if (t) {
      printf("%d", n - b[n]);
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) col[i] = false;
  for (int i = 1; i <= n; i++) col[a[i]] = true;
  int cnt = 1, i = 1;
  while (cnt != n + 1) {
    if (col[cnt]) cnt++;
    ans++;
    col[b[i]] = true;
    i++;
  }
  printf("%d", ans);
  return 0;
}
