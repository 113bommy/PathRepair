#include <bits/stdc++.h>
using namespace std;
int f[200005][26], vis[26];
int f2[200005][26], vis2[26];
int l[200005], r[200005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < 26; ++i) vis[i] = s.size();
  for (int i = s.size() - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) f[i][j] = vis[j];
    vis[s[i] - 'a'] = i;
  }
  int tmp = vis[t[0] - 'a'];
  l[0] = tmp;
  for (int i = 1; i < t.size(); ++i) {
    tmp = f[tmp][t[i] - 'a'];
    l[i] = tmp;
  }
  for (int i = 0; i < 26; ++i) vis2[i] = -1;
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j < 26; ++j) f2[i][j] = vis2[j];
    vis2[s[i] - 'a'] = i;
  }
  tmp = vis2[t.back() - 'a'];
  r[t.size() - 1] = tmp;
  for (int i = t.size() - 2; i >= 0; --i) {
    tmp = f2[tmp][t[i] - 'a'];
    r[i] = tmp;
  }
  int ans = 0;
  ans = max(ans, r[0]);
  ans = max(ans, (int)(s.size() - l[t.size() - 1]) - 1);
  for (int i = 0; i < (int)(t.size() - 1); ++i)
    ans = max(ans, r[i + 1] - l[i] - 1);
  cout << ans << '\n';
}
