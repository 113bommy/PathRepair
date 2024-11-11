#include <bits/stdc++.h>
using namespace std;
const int maxi = 1e6 + 10;
int a[maxi];
string s;
long long n, m, q;
vector<int> v[maxi];
int x[maxi], y[maxi];
int check(int mid) {
  for (int i = 1; i <= 2 * n; i++) v[i].clear();
  for (int i = 1; i <= mid; i++) v[x[i]].push_back(y[i]);
  for (int i = 1; i <= 2 * n; i++) sort(v[i].begin(), v[i].end());
  int last = 0;
  for (int i = 1; i <= 2 * n; i++)
    if (i & 1) {
      if (i == 1) {
        if (v[i].size() == 0)
          last = n;
        else
          last = v[i][0] / 2;
      } else {
        int mi = n;
        if (v[i].size()) mi = v[i][0] / 2;
        last = min(mi, (int)n - last);
      }
    } else {
      int mi = n;
      int sz = v[i].size();
      if (sz) mi = n - v[i][sz - 1] / 2;
      if (last + mi < n) return 0;
      last = min(mi, (int)n - last);
    }
  return 1;
}
void solve() {
  cin >> n >> m >> q;
  for (int i = 1; i <= q; i++) scanf("%d%d", &x[i], &y[i]);
  int l = 0;
  int r = q + 1;
  while (l < r - 1) {
    int mid = l + r >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  for (int i = 1; i <= q; i++)
    if (i <= l)
      printf("YES\n");
    else
      printf("NO\n");
}
int main() {
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
