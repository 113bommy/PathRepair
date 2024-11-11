#include <bits/stdc++.h>
using namespace std;
struct point {
  long long a;
  long long b;
} p[100005];
long long sum[100005] = {0}, mysort[100005], n, m;
bool cmp(point x, point y) {
  if (x.a != y.a)
    return x.a > y.a;
  else
    return x.b > y.b;
}
int main() {
  int t;
  cin >> t;
  sum[0] = 0;
  while (t--) {
    cin >> n >> m;
    long long ans = 0;
    long long mmax = 0;
    for (int i = 1; i <= m; i++) {
      scanf("%d%d", &p[i].a, &p[i].b);
      mmax = max(mmax, p[i].a);
    }
    sort(p + 1, p + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
      sum[i] = sum[i - 1] + p[i].a;
      mysort[i] = p[i].a;
    }
    for (int i = 1; i <= m; i++) {
      int pos =
          lower_bound(mysort + 1, mysort + m + 1, p[i].b, greater<int>()) -
          mysort;
      pos--;
      if (pos > n)
        ans = max(ans, sum[n]);
      else if (pos < i)
        ans = max(ans, 1ll * sum[pos] + p[i].a + 1ll * (n - pos - 1) * p[i].b);
      else
        ans = max(ans, 1ll * sum[pos] + 1ll * (n - pos) * p[i].b);
    }
    cout << ans << endl;
  }
}
