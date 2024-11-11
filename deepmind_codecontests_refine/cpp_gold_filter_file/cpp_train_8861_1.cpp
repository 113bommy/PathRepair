#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[100066], c[100066];
struct node {
  long long w, id;
} p[100066];
bool cmp(node x, node y) {
  if (x.w != y.w) return x.w < y.w;
  return x.id < y.id;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 1; i <= n; i++) {
    p[i].w = c[i];
    p[i].id = i;
  }
  sort(p + 1, p + 1 + n, cmp);
  int tot = 1;
  for (int i = 1; i <= m; i++) {
    long long j, d, ans = 0;
    cin >> j >> d;
    if (a[j] >= d) {
      a[j] -= d;
      ans = d * c[j];
    } else {
      d -= a[j];
      ans += c[j] * a[j];
      a[j] = 0;
      while (d > 0 && tot <= n) {
        if (a[p[tot].id] == 0) tot++;
        if (d <= a[p[tot].id]) {
          a[p[tot].id] -= d;
          ans += c[p[tot].id] * d;
          d = 0;
        } else {
          d -= a[p[tot].id];
          ans += c[p[tot].id] * a[p[tot].id];
          a[p[tot].id] = 0;
          tot++;
          if (tot > n) {
            ans = 0;
            break;
          }
        }
      }
    }
    cout << ans << endl;
  }
}
