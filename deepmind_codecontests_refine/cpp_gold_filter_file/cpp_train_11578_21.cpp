#include <bits/stdc++.h>
using namespace std;
long long int po(long long int x, long long int n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return po((x * x) % 1000000007, n / 2);
  else
    return (x * po((x * x) % 1000000007, (n - 1) / 2)) % 1000000007;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int m, n, k, t;
  cin >> m >> n >> k >> t;
  long long int a[m];
  for (int i = 0; i < m; ++i) cin >> a[i];
  sort(a, a + m);
  vector<pair<long long int, pair<long long int, long long int>>> tr(k);
  for (int i = 0; i < k; ++i)
    cin >> tr[i].second.first >> tr[i].second.second >> tr[i].first;
  sort(tr.begin(), tr.end());
  long long int an = 0;
  long long int l = 0, h = m - 1;
  while (l <= h) {
    long long int mi = (l + h) / 2;
    long long int d = a[mi] + 1;
    vector<pair<long long int, long long int>> te;
    for (int i = 0; i < k; ++i)
      if (tr[i].first >= d)
        te.push_back(make_pair(tr[i].second.first, tr[i].second.second));
    sort(te.begin(), te.end());
    if (te.size() == 0) {
      an = max(an, m - mi);
      h = mi - 1;
      continue;
    }
    long long int ti = 0;
    long long int st = te[0].first;
    long long int en = te[0].second;
    long long int lt = 0;
    for (int i = 1; i < te.size(); ++i) {
      if (te[i].first <= en) {
        en = max(en, te[i].second);
        continue;
      } else {
        ti += en - lt + 2 * (en - st + 1);
        lt = en;
        st = te[i].first;
        en = te[i].second;
      }
    }
    ti += en - lt + 2 * (en - st + 1);
    ti += n + 1 - en;
    if (ti <= t) {
      an = max(an, m - mi);
      h = mi - 1;
    } else
      l = mi + 1;
  }
  cout << an;
}
