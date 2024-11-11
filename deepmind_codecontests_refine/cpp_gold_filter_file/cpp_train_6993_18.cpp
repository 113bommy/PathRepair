#include <bits/stdc++.h>
using namespace std;
int n, q, i, j, a[2 * 100500], l[2 * 100500], r[2 * 100500], M[2 * 100500], ans,
    mn;
vector<pair<int, int> > v;
int main() {
  cin >> n >> q;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    r[a[i]] = i;
    if (l[a[i]] == 0) l[a[i]] = i;
    M[a[i]]++;
  }
  for (i = 1; i <= 2 * 100500; i++)
    if (r[i] != 0) v.push_back({l[i], r[i]});
  sort(v.begin(), v.end());
  ans = 0;
  for (i = 0; i < v.size(); i++) {
    int R = v[i].second;
    int L = v[i].first;
    j = i + 1;
    while (j < v.size() && R > v[j].first) {
      R = max(R, v[j].second);
      j++;
    }
    if (j == i + 1) continue;
    mn = 999999999;
    while (i < j) {
      mn = min(mn, (R - L + 1) - M[a[v[i].first]]);
      i++;
    }
    i--;
    ans += mn;
  }
  cout << ans;
}
