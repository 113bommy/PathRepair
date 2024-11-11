#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int a[200005];
map<int, vector<int> > mp;
void solve() {
  int n, k;
  cin >> n >> k;
  mp.clear();
  memset(a, 0, n * sizeof(a[0]));
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (mp[x].size() < k) mp[x].push_back(i);
  }
  int m = 0;
  for (auto p : mp) m += p.second.size();
  m -= m % k;
  int color = 0;
  bool ok = 0;
  for (auto e : mp) {
    for (auto c : e.second) {
      a[c] = ++color;
      color %= k;
      if (--m == 0) {
        ok = 1;
        break;
      }
    }
    if (ok) break;
  }
  if (ok) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << '\n';
  }
}
int main() {
  fast();
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
