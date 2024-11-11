#include <bits/stdc++.h>
using namespace std;
long long a[200100], s[200100], t[200100], ans[200100];
double inter(long long u, long long v) {
  return (double)(s[u] - s[v]) / (double)(u - v);
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  int l = 0, r = 0;
  for (int i = n; i >= 0; i--) {
    while (r - l > 1 && inter(t[r - 1], t[r - 2]) <= inter(t[r - 2], i)) r--;
    t[r++] = i;
  }
  for (int i = 1; i <= n; i++) {
    int u = 0, v = r - 1;
    while (u < v - 1) {
      int m = (u + v) / 2;
      if (inter(t[m], t[m + 1]) <= a[i])
        v = m;
      else
        u = m + 1;
    }
    ans[i] = min(s[t[v]] - a[i] * t[v] - s[i] + a[i] * i,
                 s[t[u]] - a[i] * t[u] - s[i] + a[i] * i);
  }
  long long w = 0, mn = 0;
  for (int i = 1; i <= n; i++) w += a[i] * i;
  for (int i = 1; i <= n; i++) mn = min(mn, ans[i]);
  w -= mn;
  cout << w << endl;
  return 0;
}
