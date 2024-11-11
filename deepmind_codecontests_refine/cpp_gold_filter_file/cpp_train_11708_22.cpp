#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
long long ans = 0;
int n, m;
vector<pair<string, int>> a;
string s = "";
map<vector<int>, int> sp1, sp2;
void gen1() {
  if (s.size() == min(20, n)) {
    vector<int> gg = {};
    for (auto d : a) {
      int cnt = 0;
      for (int i = 0; i < s.size(); ++i) cnt += (s[i] == d.first[i]);
      if (cnt > d.second) return;
      gg.push_back(d.second - cnt);
    }
    ++sp1[gg];
    return;
  }
  s += '0';
  gen1();
  s.pop_back();
  s += '1';
  gen1();
  s.pop_back();
}
void gen2() {
  if (s.size() == n - 20) {
    vector<int> gg = {};
    for (auto d : a) {
      int cnt = 0;
      for (int i = 0; i < s.size(); ++i) cnt += (s[i] == d.first[20 + i]);
      if (cnt > d.second) return;
      gg.push_back(cnt);
    }
    ++sp2[gg];
    return;
  }
  s += '0';
  gen2();
  s.pop_back();
  s += '1';
  gen2();
  s.pop_back();
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    string s;
    int t;
    cin >> s >> t;
    a.push_back({s, t});
  }
  gen1();
  if (n <= 20) {
    vector<int> gg = {};
    for (auto d : a) {
      gg.push_back(0);
    }
    cout << sp1[gg] << '\n';
    return;
  }
  s = "";
  if (n > 20) gen2();
  int ans = 0;
  for (auto d : sp1) {
    ans += (long long)d.second * (long long)sp2[d.first];
  }
  cout << ans << '\n';
}
