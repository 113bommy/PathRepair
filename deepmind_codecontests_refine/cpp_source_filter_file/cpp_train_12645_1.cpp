#include <bits/stdc++.h>
using namespace std;
int r(int a) { return (a - 1) ? 1 : 2; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<vector<int> > v(3);
  vector<pair<int, int> > ans;
  ans.clear();
  v[1].clear();
  v[2].clear();
  int n, a[100005];
  cin >> n;
  for (int i = 0; i < int(n); ++i) cin >> a[i], v[a[i]].push_back(i);
  for (int i = 0; i < int(max((int)(v[1].size()), (int)(v[2].size()))); ++i) {
    int len = i, pt[3] = {0}, st[3] = {0}, flag = 1, last;
    for (int j = 0; j < int(n); ++j) {
      if (pt[a[j]] + len < (int)(v[a[j]].size())) {
        if ((v[a[j]][pt[a[j]] + len] - v[a[j]][pt[a[j]]] + 1) < 2 * (len + 1)) {
          last = a[j];
          st[a[j]]++;
          pt[r(a[j])] += v[a[j]][pt[a[j]] + len] - v[a[j]][pt[a[j]]] - len;
          pt[a[j]] += len + 1;
          j = v[a[j]][pt[a[j]] - 1];
        } else {
          last = r(a[j]);
          st[r(a[j])]++;
          pt[a[j]] += v[r(a[j])][pt[r(a[j])] + len] - j - len;
          pt[r(a[j])] += len + 1;
          j = v[r(a[j])][pt[r(a[j])] - 1];
        }
      } else if (pt[r(a[j])] + len < (int)(v[r(a[j])].size())) {
        st[r(a[j])]++;
        last = r(a[j]);
        pt[r(a[j])] += len + 1;
        pt[a[j]] = 1e6;
        j = v[r(a[j])][pt[r(a[j])] - 1];
      } else {
        flag = 0;
        break;
      }
    }
    if (flag && st[1] != st[2]) {
      if (st[1] > st[2] && last == 1)
        ans.push_back({st[1], len + 1});
      else if (st[2] > st[1] && last == 2)
        ans.push_back({st[1], len + 1});
    }
  }
  if (ans.empty())
    cout << 0;
  else {
    cout << (int)(ans.size()) << endl;
    reverse(ans.begin(), ans.end());
    for (auto i : ans) cout << i.first << " " << i.second << endl;
  }
  return 0;
}
