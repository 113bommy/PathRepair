#include <bits/stdc++.h>
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")
using namespace std;
string itosm(long long x) {
  if (x == 0) return "0";
  string ans = "";
  while (x > 0) {
    ans += ((x % 10) + '0');
    x /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
long long stoim(string str) {
  long long ans = 0;
  long long k = 1;
  for (int i = str.length() - 1; i >= 0; i--) {
    ans += (str[i] - '0') * k;
    k *= 10;
  }
  return ans;
}
const long long infll = 1e18 + 3;
const int inf = 1009000999;
const double eps = 1e-7;
const int maxn = 3e6 + 46;
const int baseint = 1000200013;
const long long basell = 1e18 + 3;
const long double PI = acos(-1.0);
const long long mod = 1e9 + 7;
pair<int, int> a[maxn];
int ans[maxn];
vector<pair<int, int> > f;
void solve() {
  int n;
  cin >> n;
  f.clear();
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    f.push_back({a[i].first, -i});
    f.push_back({a[i].second, i});
  }
  sort(f.begin(), f.end());
  for (int i = 0; i <= n; i++) ans[i] = 0;
  set<pair<int, int> > s;
  int t = 0;
  for (pair<int, int> x : f) {
    while (t != x.first) {
      if (s.size()) {
        ans[(*s.begin()).second] = t;
        s.erase(s.find(*s.begin()));
      }
      t++;
    }
    x.second *= -1;
    if (x.second > 0) {
      s.insert(x);
    } else {
      x.second *= -1;
      x.first = a[x.second].first;
      if (s.count(x)) s.erase(x);
    }
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << "\n";
}
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  ;
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
