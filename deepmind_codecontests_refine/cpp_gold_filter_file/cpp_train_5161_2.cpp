#include <bits/stdc++.h>
using namespace std;
ifstream fin("f.in");
int k, n;
int a[100005];
map<string, vector<int> > mp;
map<string, bool> vis;
bool cmp(int a, int b) { return a > b; }
int getPair(string s) {
  if (vis[s]) return false;
  vis[s] = true;
  vector<int> v1;
  vector<int> v2;
  for (auto x : mp[s]) v1.push_back(x);
  reverse(s.begin(), s.end());
  vis[s] = true;
  for (auto x : mp[s]) v2.push_back(x);
  sort(v1.rbegin(), v1.rend());
  sort(v2.rbegin(), v2.rend());
  int ret = 0;
  int sz = min(v1.size(), v2.size());
  for (int i = 0; i < sz; ++i) {
    if (v1[i] + v2[i] <= 0) break;
    ret += v1[i] + v2[i];
  }
  return ret;
}
int getPal(string s) {
  vector<int> v;
  for (int x : mp[s]) v.push_back(x);
  sort(v.rbegin(), v.rend());
  int sz = v.size();
  int ret = 0;
  int tmp = 0;
  for (int i = 0; i < sz; ++i) {
    tmp += v[i];
    if (i & 1) ret = max(tmp, ret);
  }
  return ret;
}
int getMid(string s) {
  vector<int> v;
  for (int x : mp[s]) v.push_back(x);
  sort(v.rbegin(), v.rend());
  int sz = v.size();
  int ret = 0;
  int tmp = 0;
  for (int i = 0; i < sz; ++i) {
    tmp += v[i];
    if (!(i & 1)) {
      ret = max(tmp, ret);
    }
  }
  return ret;
}
bool isPal(string s) {
  int sz = s.size();
  for (int i = 0; i < sz / 2; ++i) {
    if (s[i] != s[sz - 1 - i]) {
      return false;
    }
  }
  return true;
}
void solve() {
  cin >> k >> n;
  for (int i = 0; i < k; ++i) {
    string s;
    cin >> s >> a[i];
    mp[s].push_back(a[i]);
  }
  int ans = 0;
  for (auto x : mp) {
    if (isPal(x.first)) {
      ans += getPal(x.first);
    } else {
      ans += getPair(x.first);
    }
  }
  int tmp = 0;
  for (auto x : mp) {
    if (isPal(x.first)) tmp = max(tmp, getMid(x.first) - getPal(x.first));
  }
  ans += tmp;
  cout << ans << endl;
}
int main() {
  solve();
  return 0;
}
