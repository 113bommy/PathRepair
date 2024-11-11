#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
map<int, int> q;
int n, m, a[N], p[33], l[N], r[N];
int main() {
  cin >> n;
  for (int i = 1; i <= int(n); i++) scanf("%d", &a[i]);
  for (int i = 0; i <= int(30); i++) p[i] = 0;
  for (int i = 1; i <= int(n); i++) {
    for (int j = 0; j <= int(30); j++)
      if (a[i] >> j & 1)
        p[j] = i;
      else
        l[i] = max(l[i], p[j]);
  }
  for (int i = 0; i <= int(30); i++) p[i] = n + 1;
  for (int i = n; i >= int(1); i--) {
    r[i] = n + 1;
    for (int j = 0; j <= int(30); j++)
      if (a[i] >> j & 1)
        p[j] = i;
      else
        r[i] = min(r[i], p[j]);
    if (q.count(a[i])) r[i] = min(q[a[i]], r[i]);
    q[a[i]] = i;
  }
  long long ans = 1LL * n * (n + 1) / 2;
  for (int i = 1; i <= int(n); i++) ans -= 1LL * (r[i] - i) * (i - l[i]);
  cout << ans << endl;
}
