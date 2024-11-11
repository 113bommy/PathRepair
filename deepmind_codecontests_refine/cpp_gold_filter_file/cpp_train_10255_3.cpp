#include <bits/stdc++.h>
using namespace std;
pair<int, int> b[2005], c[2005], ans[2005 * 2005];
int cnt, val, pos[2005], a[2005];
int main() {
  int n, x;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    a[i] = x;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    b[i] = make_pair(x, i);
  }
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; i++) {
    a[i] = b[a[i]].second;
    c[i].first = a[i];
    c[i].second = i;
  }
  sort(c + 1, c + 1 + n);
  for (int i = n; i >= 1; i--) {
    int s = c[i].second;
    for (int j = s + 1; j <= i; j++) {
      if (a[j] <= s) {
        ans[++cnt] = make_pair(s, j);
        swap(a[s], a[j]);
        val += abs(s - j);
        s = j;
      }
    }
  }
  printf("%d\n%d\n", val, cnt);
  for (int i = 1; i <= cnt; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
