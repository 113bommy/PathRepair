#include <bits/stdc++.h>
using namespace std;
struct AC {
  vector<vector<int>> ch;
  vector<int> f, cnt;
  AC() { extend(); }
  void extend() {
    ch.emplace_back(26);
    cnt.push_back(0);
  }
  void insert(string s, int d) {
    int i = 0;
    for (char c : s) {
      if (!ch[i][c - 'a']) ch[i][c - 'a'] = ch.size(), extend();
      i = ch[i][c - 'a'];
    }
    cnt[i] += d;
  }
  void fail() {
    f.assign(ch.size(), 0);
    queue<int> q;
    for (int i = 0; i < 26; ++i)
      if (ch[0][i]) q.push(ch[0][i]);
    while (!q.empty()) {
      int i = q.front();
      q.pop();
      for (int j = 0; j < 26; ++j)
        if (ch[i][j]) {
          int &it = f[ch[i][j]] = f[i];
          while (it && !ch[it][j]) it = f[it];
          it = ch[it][j];
          cnt[ch[i][j]] += cnt[it];
          q.push(ch[i][j]);
        }
    }
  }
} ac;
int main() {
  string s, s1, s2;
  cin >> s >> s1 >> s2;
  ac.insert(s1, 1), ac.insert(s2, -1);
  ac.fail();
  int n = s.length(), dp[n + 1][ac.ch.size()];
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j < ac.ch.size(); ++j) dp[i][j] = -n;
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < ac.ch.size(); ++j)
      for (int c = 0; c < 26; ++c)
        if (s[i] - 'a' == c || s[i] == '*') {
          int tmp = j;
          while (tmp && !ac.ch[tmp][c]) tmp = ac.f[tmp];
          tmp = ac.ch[tmp][c];
          dp[i + 1][tmp] = max(dp[i + 1][tmp], dp[i][j] + ac.cnt[tmp]);
        }
  int ans = -n;
  for (int i = 0; i < ac.ch.size(); ++i) ans = max(ans, dp[n][i]);
  cout << ans;
}
