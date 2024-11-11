#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void solve() {
  string s;
  cin >> s;
  vector<pair<char, int>> v{};
  v.push_back({s[0], 1});
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == s[i - 1])
      v.at(v.size() - 1).second++;
    else
      v.push_back({s[i], 1});
  }
  map<char, char> m;
  for (int i = 0; i < 26; i++) {
    m.insert({i + 'a', ' '});
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    string t;
    cin >> t;
    m[t[0]] = t[1];
    m[t[1]] = t[0];
  }
  int length = s.length();
  int left = v[0].second;
  int right = 0;
  bool c = false;
  char prev = v[0].first;
  for (int i = 1; i < v.size(); i++) {
    if (m[v[i].first] == prev) {
      c = true;
      if (i % 2 == 1)
        right += v[i].second;
      else
        left += v[i].second;
      prev = v[i].first;
    } else {
      if (c) length -= min(right, left);
      c = false;
      if (i % 2 == 1) {
        right = v[i].second;
        left = 0;
      } else {
        left = v[i].second;
        right = 0;
      }
      prev = v[i].first;
    }
  }
  if (c) length -= min(right, left);
  cout << s.length() - length << "\n";
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
