#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int SQRT = 330;
int n, q, a[MAXN], ans[MAXN], dd[MAXN], td[MAXN], prv[MAXN], last[MAXN],
    cnt[MAXN];
pair<pair<int, int>, int> vec[MAXN];
bool mark[MAXN];
deque<int> qq[MAXN];
bool cmp(pair<pair<int, int>, int> u, pair<pair<int, int>, int> v) {
  if (u.first.first / SQRT != v.first.first / SQRT)
    return u.first.first < v.first.first;
  return u.first.second < v.first.second;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(last, -1, sizeof(last));
  for (int i = 0; i < n; i++) prv[i] = last[a[i]], last[a[i]] = i;
  for (int i = 0; i < n; i++) {
    if (prv[i] == -1)
      dd[i] = -1;
    else {
      if (prv[prv[i]] == -1 || i - prv[i] == prv[i] - prv[prv[i]])
        dd[i] = dd[prv[i]];
      else
        dd[i] = prv[prv[i]];
    }
  }
  cin >> q;
  for (int i = 0; i < q; i++)
    cin >> vec[i].first.first >> vec[i].first.second, vec[i].first.first--,
        vec[i].second = i;
  sort(vec, vec + q, cmp);
  int l = 0, r = 0, cc = 0, cn = 0;
  for (int i = 0; i < q; i++) {
    int tl = vec[i].first.first, tr = vec[i].first.second;
    while (r < tr) {
      if (cnt[a[r]]++ == 0) cc++;
      if (mark[a[r]]) cn--, mark[a[r]] = 0;
      if (dd[r] < l) mark[a[r]] = 1, cn++;
      qq[a[r]].push_back(r), r++;
    }
    while (l > tl) {
      l--;
      if (cnt[a[l]]++ == 0) cc++;
      if (mark[a[l]]) cn--, mark[a[l]] = 0;
      qq[a[l]].push_front(l);
      if (dd[qq[a[l]].back()] < l) mark[a[l]] = 1, cn++;
    }
    while (tr < r) {
      r--;
      if (--cnt[a[r]] == 0) cc--;
      if (mark[a[r]]) mark[a[r]] = 0, cn--;
      qq[a[r]].pop_back();
      if (qq[a[r]].size() && dd[qq[a[r]].back()] < l) mark[a[r]] = 1, cn++;
    }
    while (l < tl) {
      if (--cnt[a[l]] == 0) cc--;
      if (mark[a[l]]) mark[a[l]] = 0, cn--;
      qq[a[l]].pop_front();
      if (qq[a[l]].size() && dd[qq[a[l]].back()] < l) mark[a[l]] = 1, cn++;
      l++;
    }
    if (cn)
      ans[vec[i].second] = cc;
    else
      ans[vec[i].second] = cc + 1;
  }
  for (int i = 0; i < q; i++) cout << ans[i] << "\n";
  return 0;
}
