#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int n;
int a[200005];
int ans[20];
int vis[200005];
int cnt = 0;
bool ok(int pos) {
  if (pos % 2) {
    if (pos - 1 >= 1) {
      if (a[pos] < a[pos - 1])
        ;
      else
        return 0;
    }
    if (pos + 1 <= n) {
      if (a[pos] < a[pos + 1])
        ;
      else
        return 0;
    }
  } else {
    if (pos - 1 >= 1) {
      if (a[pos] > a[pos - 1])
        ;
      else
        return 0;
    }
    if (pos + 1 <= n) {
      if (a[pos] > a[pos + 1])
        ;
      else
        return 0;
    }
  }
  return 1;
}
bool check(int pos1, int pos2) {
  for (int i = 1; i <= cnt; i++) {
    if (!ok(ans[i])) return 0;
  }
  if (!ok(pos1)) return 0;
  if (!ok(pos2)) return 0;
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 2; i <= n; i += 2) {
    if (a[i] <= a[i - 1] || (i + 1 <= n && a[i] <= a[i + 1]))
      cnt++, ans[cnt] = i;
  }
  if (cnt > 4) {
    printf("-1\n");
    return 0;
  }
  int tot = 0;
  for (int i = 1; i <= cnt; i++) {
    int ppos = ans[i];
    for (int j = -1; j <= 1; j++) {
      int pos = j + ppos;
      if (!vis[pos] && pos >= 1 && pos <= n) {
        for (int k = 1; k <= n; k++) {
          if (vis[k]) continue;
          swap(a[pos], a[k]);
          if (check(pos, k)) tot++;
          swap(a[pos], a[k]);
        }
        vis[pos] = 1;
      }
    }
  }
  cout << tot << endl;
  return 0;
}
