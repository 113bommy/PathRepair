#include <bits/stdc++.h>
using namespace std;
void IO() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const int maxn = 1000 + 10;
int n, k, mx;
vector<int> vec[maxn];
int query(int a, int b) {
  cout << "? " << (b - a + 1);
  for (int i = 0; i < (b - a + 1); i++) cout << ' ' << a + i;
  cout << endl;
  int ans;
  cin >> ans;
  return ans;
}
int query(vector<int> &v) {
  cout << "? " << v.size();
  for (const auto &x : v) cout << ' ' << x;
  cout << endl;
  int ans;
  cin >> ans;
  return ans;
}
int l, r;
bool check(int mid) { return query(l, mid) == mx; }
void solve() {
  cin >> n >> k;
  for (int i = 0, c; i < k; i++) {
    vec[i].clear();
    cin >> c;
    for (int j = 0, t; j < c; j++) {
      cin >> t;
      vec[i].push_back(t);
    }
  }
  mx = query(1, n);
  l = 1, r = n + 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  int id, idans;
  for (int i = 0; i < k; i++) {
    bool ok = true;
    for (const auto &x : vec[i])
      if (x == l) ok = false;
    if (!ok) {
      id = i;
      map<int, bool> mp;
      for (const auto &x : vec[i]) mp[x] = true;
      vector<int> tem;
      for (int i = 1; i <= n; i++)
        if (!mp[i]) tem.push_back(i);
      idans = query(tem);
    }
  }
  cout << "!";
  for (int i = 0; i < k; i++)
    if (i != id)
      cout << ' ' << mx;
    else
      cout << ' ' << idans;
  cout << endl;
  string s;
  cin >> s;
}
int main() {
  IO();
  int _ = 1;
  cin >> _;
  while (_--) solve();
}
