#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const double pi = acos(-1.0);
int n;
long long A, cf, cm;
long long m;
long long pre[N];
int ans[N];
struct node {
  int id;
  long long w;
  bool operator<(const node& temp) const {
    return w == temp.w ? id < temp.id : w < temp.w;
  }
} p[N];
int a[N];
int res[N];
int main() {
  cin >> n >> A >> cf >> cm >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &p[i].w);
    p[i].id = i;
    res[i] = p[i].w;
  }
  sort(p + 1, p + 1 + n);
  for (int i = 1; i <= n; i++) {
    a[i] = p[i].w;
    pre[i] = pre[i - 1] + a[i];
  }
  int val = 0, besti = 0, qianmiani;
  long long ans = -1;
  for (int i = n; i >= 0; i--) {
    long long lef = m - (A * (n - i) - (pre[n] - pre[i]));
    if (lef < 0) break;
    long long l = 0, r = A;
    while (l < r) {
      long long mid = (r + l + 1) / 2;
      int x = lower_bound(a + 1, a + i + 1, mid) - a - 1;
      if (mid * x - pre[x] <= lef)
        l = mid;
      else
        r = mid - 1;
    }
    if (l * cm + cf * (n - i) > ans)
      ans = l * cm + cf * (n - i), val = l, besti = i;
  }
  cout << ans << endl;
  for (int i = 1; i <= n; i++)
    if (res[i] < val) res[i] = val;
  for (int i = besti + 1; i <= n; i++) res[p[i].id] = A;
  for (int i = 1; i <= n; i++) printf("%d%c", res[i], i == n ? '\n' : ' ');
  return 0;
}
