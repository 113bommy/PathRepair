#include <bits/stdc++.h>
using namespace std;
const int N = (int)4e5 + 9;
int a[N];
int lf[N];
int rf[N];
int no[N];
vector<pair<int, int> > F[N];
int res1[N];
int iq[N];
int vv[N];
void solve(int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  vector<pair<int, int> > tt;
  for (int i = r; i > mid; i--) {
    tt.push_back(make_pair(a[i], rf[i]));
  }
  tt.push_back(make_pair((int)1e9 + 579, 0));
  sort(tt.begin(), tt.end());
  for (int i = (int)tt.size() - 2; i >= 0; i--) {
    tt[i].second = max(tt[i].second, tt[i + 1].second);
  }
  int res = tt[0].second;
  int id;
  for (int i = l; i <= mid; i++) {
    no[i] = max(no[i], res);
    id =
        upper_bound(tt.begin(), tt.end(), make_pair(a[i] + 1, -1)) - tt.begin();
    res = max(res, lf[i] + tt[id].second);
  }
  tt.clear();
  for (int i = l; i <= mid; i++) {
    tt.push_back(make_pair(a[i], lf[i]));
  }
  tt.push_back(make_pair(0, 0));
  sort(tt.begin(), tt.end());
  for (int i = 1; i < tt.size(); i++)
    tt[i].second = max(tt[i].second, tt[i - 1].second);
  int li, ri, mi;
  res = tt[(int)tt.size() - 1].second;
  for (int i = r; i > mid; i--) {
    no[i] = max(no[i], res);
    li = 0, ri = tt.size();
    while (li + 1 < ri) {
      mi = (li + ri) / 2;
      if (tt[mi].first < a[i])
        li = mi;
      else
        ri = mi;
    }
    res = max(res, rf[i] + tt[li].second);
  }
  solve(l, mid);
  solve(mid + 1, r);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= q; i++) {
    cin >> iq[i] >> vv[i];
    res1[i] = 1;
    F[iq[i]].push_back(make_pair(vv[i], i));
  }
  vector<int> cur;
  cur.push_back(0);
  int x;
  int id;
  for (int i = 1; i <= n; i++) {
    for (auto p : F[i]) {
      id = lower_bound(cur.begin(), cur.end(), p.first) - cur.begin();
      id--;
      res1[p.second] += id;
    }
    x = lower_bound(cur.begin(), cur.end(), a[i]) - cur.begin();
    if (x == cur.size())
      cur.push_back(a[i]);
    else
      cur[x] = min(cur[x], a[i]);
    lf[i] = x;
  }
  cur.clear();
  cur.push_back((int)2e9 + 11);
  int li, ri, md;
  for (int i = n; i >= 1; i--) {
    for (auto p : F[i]) {
      li = 0, ri = (int)cur.size();
      while (li < ri) {
        md = (li + ri) / 2;
        if (cur[md] >= p.first)
          li = md + 1;
        else
          ri = md;
      }
      res1[p.second] += li - 1;
    }
    li = 0, ri = (int)cur.size();
    while (li < ri) {
      md = (li + ri) / 2;
      if (cur[md] >= a[i])
        li = md + 1;
      else
        ri = md;
    }
    if (li == (int)cur.size())
      cur.push_back(a[i]);
    else
      cur[li] = max(cur[li], a[i]);
    rf[i] = li;
  }
  solve(1, n);
  for (int i = 1; i <= q; i++) {
    cout << max(res1[i], no[i]) << "\n";
  }
  return 0;
}
