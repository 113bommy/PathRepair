#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
const ll inf = 2e18;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 5;
string s, t;
int n, a[N];
int f(int x) {
  map<char, set<int>> mp;
  for (int i = 0; i < n; i++) mp[s[i]].insert(i);
  for (int i = 0; i < x; i++) {
    mp[s[a[i] - 1]].erase(a[i] - 1);
  }
  if (!mp[t[0]].size()) {
    return 0;
  }
  int st = *mp[t[0]].begin();
  for (int i = 1; i < t.size(); i++) {
    if (!mp[t[i]].size()) {
      return 0;
    }
    if (mp[t[i]].upper_bound(st) == mp[t[i]].end()) return 0;
    st = *mp[t[i]].upper_bound(st);
  }
  return 1;
}
void code() {
  cin >> s >> t;
  n = s.size();
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int lo = 1, hi = n;
  while (lo < hi) {
    int mid = lo + (hi - lo + 1) / 2;
    if (f(mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  cout << lo << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t-- > 0) {
    code();
  }
}
