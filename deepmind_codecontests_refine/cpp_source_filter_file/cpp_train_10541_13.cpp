#include <bits/stdc++.h>
using namespace std;
int dp[512][512];
int dp1[512][512];
pair<int, int> par[512][512];
string s;
int k;
long long calc(long long x1, long long x2) {
  long long cnt = 0;
  for (; x1 <= x2;) {
    if (s[x1] != s[x2]) cnt++;
    x1++;
    x2--;
  }
  return cnt;
}
string closest_pal(string s) {
  string s1 = s;
  long long i = 0, j = s.size() - 1;
  while (i <= j) {
    if (s1[i] != s1[j]) s1[j] = s1[i];
    i++;
    j--;
  }
  return s1;
}
int main() {
  cin >> s;
  cin >> k;
  for (int i1 = 0; i1 < s.size(); i1++) {
    for (int i2 = i1; i2 < s.size(); i2++) {
      dp[i1][i2] = calc(i1, i2);
    }
  }
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j <= k; j++) {
      dp1[i][j] = s.size() + 2;
      par[i][j] = {-1, -1};
    }
  }
  for (int i = 0; i < s.size(); i++) {
    dp1[i][1] = dp[0][i];
    par[i][1] = {-1, -1};
  }
  for (int i = 0; i < s.size(); i++) {
    for (int j = 1; j < k; j++) {
      for (int i1 = i1 + 1; i1 < s.size(); i1++) {
        long long t = dp1[i][j] + dp[i + 1][i1];
        if (t < dp1[i1][j + 1]) {
          dp1[i1][j + 1] = t;
          par[i1][j + 1] = {i, j};
        }
      }
    }
  }
  vector<string> v;
  pair<long long, long long> ans = {s.size() + 2, -1};
  for (int i = 1; i <= k; i++) {
    ans = min(ans, {dp1[s.size() - 1][i], i});
  }
  cout << ans.first << endl;
  int x = s.size() - 1, y = ans.second;
  for (; x != -1;) {
    pair<int, int> p = par[x][y];
    string ss = "";
    for (int i = p.first + 1; i <= x; i++) ss += s[i];
    v.push_back(closest_pal(ss));
    x = p.first;
    y = p.second;
  }
  for (int i = v.size() - 1; i >= 0; i--) {
    cout << v[i];
    if (i != 0) cout << "+";
  }
  cout << endl;
  return 0;
}
