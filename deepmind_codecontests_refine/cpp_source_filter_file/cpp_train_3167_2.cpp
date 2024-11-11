#include <bits/stdc++.h>
using namespace std;
const int maxn = int(4e5) + 100;
map<int, int> M;
int n, m, a[maxn], b[maxn], q, nz, Count[maxn], dem[maxn];
vector<int> ans;
int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  sort(b + 1, b + m + 1);
  M[b[1]] = 1;
  nz = 1;
  Count[1]++;
  for (int i = 2; i <= m; i++)
    if (b[i] != b[i - 1]) {
      M[b[i]] = ++nz;
      Count[nz]++;
    } else
      Count[nz]++;
  for (int ll = 1; ll <= q; ll++) {
    long long N = (n - ll) / q + 1, Ma = 0;
    for (int i = 1; i <= m; i++) {
      if (ll + (i - 1) * q > n) break;
      int z = a[ll + (i - 1) * q], nc;
      nc = M[z];
      dem[nc]++;
      if (dem[nc] <= Count[nc] && nc != 0) Ma++;
    }
    if (Ma == m) ans.push_back(ll);
    for (int i = m + 1; i <= N; i++) {
      if (ll + (i - m + 1) * q > n) break;
      int nc = M[a[ll + (i - m - 1) * q]];
      dem[nc]--;
      if (dem[nc] < Count[nc] && nc != 0) Ma--;
      if (ll + (i - 1) * q > n) continue;
      nc = M[a[ll + (i - 1) * q]];
      dem[nc]++;
      if (dem[nc] <= Count[nc] && nc != 0) Ma++;
      if (Ma == m) ans.push_back(ll + (i - m) * q);
    }
    for (int i = 1; i <= N; i++) {
      if (ll + (i - 1) * q > n) break;
      int nc = M[a[ll + (i - 1) * q]];
      if (dem[nc] > 0) dem[nc] = 0;
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
