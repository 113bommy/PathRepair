#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
int a[maxn], n, nn, ans = 0x3f3f3f3f;
void dfs(int x, int c) {
  if (c >= ans) return;
  if (x == nn) ans = min(ans, c);
  if (a[x] == a[x + 1])
    dfs(x + 2, c);
  else {
    int dx0, dx1;
    for (int i = x + 2; i < nn; i++)
      if (a[i] == a[x])
        dx0 = i;
      else if (a[i] == a[x + 1])
        dx1 = i;
    if (dx0 > dx1 + 1) {
      int cc = 1;
      swap(a[x], a[x + 1]);
      for (int j = dx1; j > x; j--) a[j] = a[j - 1], cc++;
      dfs(x + 2, c + cc - 1);
      for (int j = x + 1; j < dx1; j++) a[j] = a[j + 1];
      a[dx1] = a[x];
      swap(a[x], a[x + 1]);
    } else {
      int cc = 0;
      for (int j = dx0; j > x; j--) a[j] = a[j - 1], cc++;
      dfs(x + 2, c + cc - 1);
      for (int j = x + 1; j < dx0; j++) a[j] = a[j + 1];
      a[dx0] = a[x];
    }
  }
}
int main() {
  cin >> n;
  nn = 2 * n;
  for (int i = 0; i < nn; i++) cin >> a[i];
  dfs(0, 0);
  cout << ans << endl;
  return 0;
}
