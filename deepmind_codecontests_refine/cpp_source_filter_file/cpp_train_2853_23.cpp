#include <bits/stdc++.h>
using namespace std;
int a[1005], n;
stack<int> sta;
vector<pair<int, int> > ans;
inline bool cmp(int x, int y) { return a[x] < a[y]; }
void solve(vector<int>& v) {
  while (1) {
    sort(v.begin(), v.end(), cmp);
    if (a[v[0]] == 0) return;
    for (int t = a[v[1]] / a[v[0]]; t; t >>= 1) {
      if (t & 1) {
        ans.emplace_back(v[0], v[1]);
        a[v[1]] -= a[v[0]];
      } else {
        ans.emplace_back(v[0], v[2]);
        a[v[2]] -= a[v[0]];
      }
      a[v[0]] <<= 1;
    }
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i]) sta.push(i);
  }
  if (sta.size() < 2) return puts("-1"), 0;
  while (sta.size() > 2) {
    int x = sta.top();
    sta.pop();
    int y = sta.top();
    sta.pop();
    int z = sta.top();
    sta.pop();
    vector<int> v;
    v.push_back(x), v.push_back(y), v.push_back(z);
    solve(v);
    if (a[x]) sta.push(a[x]);
    if (a[y]) sta.push(a[y]);
    if (a[z]) sta.push(a[z]);
  }
  cout << ans.size() << '\n';
  for (auto i : ans) cout << i.first << ' ' << i.second << '\n';
  return 0;
}
