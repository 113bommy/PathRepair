#include <bits/stdc++.h>
using namespace std;
void GO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
const long long INF = 1e9 + 7;
const long long mod = (1e9);
const int maxn = (int)2001;
const long double PI = acos(-1.0);
const long double eps = 0.000000001;
mt19937 rnd(time(0));
void solve() {
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  string s;
  cin >> s;
  int ost = 0;
  vector<pair<int, int> > seg;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') continue;
    int r = i;
    while (r < int(s.size()) && s[r] == '0') r++;
    seg.push_back({i, r - i});
    ost += (r - i) / b;
    i = r;
  }
  vector<int> ans;
  while (ost >= a) {
    if (seg.back().second < b) {
      seg.pop_back();
      continue;
    }
    ans.push_back(seg.back().first + b - 1);
    seg.back().first += b;
    seg.back().second -= b;
    ost--;
  }
  cout << int(ans.size()) << '\n';
  for (auto &i : ans) cout << i + 1 << ' ';
}
signed main() {
  GO();
  int Q = 1;
  while (Q--) {
    solve();
  }
}
