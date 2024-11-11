#include <bits/stdc++.h>
using namespace std;
struct point {
  long long l;
  long long r;
};
struct data {
  long long r;
  long long l;
  int idx;
};
bool cmp(data a, data b) {
  if (a.l < b.l)
    return true;
  else if (a.l == b.l && a.r < b.r)
    return true;
  else
    return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, n, m;
  cin >> n >> m;
  point a[n];
  long long num;
  for (i = 0; i < n; i++) cin >> a[i].l >> a[i].r;
  set<pair<long long, long long> > bridge;
  set<pair<long long, long long> >::iterator it;
  for (i = 0; i < m; i++) {
    cin >> num;
    bridge.insert(make_pair(num, i + 1));
  }
  data arr[n - 1];
  for (i = 1; i < n; i++) {
    arr[i - 1].l = a[i].r - a[i - 1].l;
    arr[i - 1].r = a[i].l - a[i - 1].r;
    arr[i - 1].idx = i - 1;
  }
  sort(arr, arr + n - 1, cmp);
  long long ans[n - 1];
  for (i = 0; i < n - 1; i++) {
    it = bridge.lower_bound(make_pair(arr[i].r, 0));
    if (it == bridge.end())
      break;
    else {
      pair<long long, long long> x;
      x = *it;
      if (arr[i].r <= x.first && x.first <= arr[i].l) {
        ans[arr[i].idx] = x.second;
        bridge.erase(it);
      } else
        break;
    }
  }
  if (i == n - 1) {
    cout << "Yes" << endl;
    for (i = 0; i < n - 1; i++) cout << ans[i] << " ";
    cout << endl;
  } else
    cout << "No" << endl;
  return 0;
}
