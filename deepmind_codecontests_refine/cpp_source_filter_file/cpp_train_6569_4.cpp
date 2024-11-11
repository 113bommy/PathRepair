#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int n, h, a[maxn], w[maxn];
int main() {
  scanf("%d%d", &n, &h);
  int s = 0;
  for (int i = 1; i <= n; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l -= s;
    r -= s;
    s += r - l;
    a[i] = l;
    w[i] = r - l;
  }
  int ans = 0;
  s = 0;
  for (int i = 1, j = 1; i <= n; i++) {
    while (j <= n && a[j] <= a[i] + h) s += w[j++];
    ans = max(ans, s);
    s -= w[i];
  }
  printf("%d", ans + h);
  return 0;
}
