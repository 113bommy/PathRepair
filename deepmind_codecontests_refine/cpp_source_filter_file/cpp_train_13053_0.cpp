#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
char buff[N];
string s, t;
int dp[N];
int pre[N];
void KMPpreprocess() {
  int n = t.length();
  int i = 0;
  int j = -1;
  dp[0] = -1;
  while (i < n) {
    while (j >= 0 && t[i] != t[j]) j = dp[j];
    j++, i++;
    dp[i] = j;
  }
}
void KMPprocess() {
  int n = s.length();
  int i = 0, j = 0;
  while (i < n) {
    while (j >= 0 && s[i] != t[j]) j = dp[j];
    j++;
    pre[i] = j;
    if (j == n) j = dp[j];
    i++;
  }
}
int d1[N];
void Manacher() {
  int l = 0, r = -1;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    int k = i > r ? 1 : min(d1[l + r - i], r - i + 1);
    while (i + k < n && i - k >= 0 && s[i - k] == s[i + k]) k++;
    d1[i] = k;
    if (i + k - 1 > r) r = i + k - 1, l = i - k;
  }
}
signed main() {
  scanf("%s", buff);
  s = t = buff;
  int n = s.length();
  reverse(t.begin(), t.end());
  KMPpreprocess();
  KMPprocess();
  Manacher();
  vector<pair<int, int> > prefix(n + 1);
  prefix[0] = make_pair(0, 0);
  for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i];
    if (pre[i] > prefix[i + 1].second) prefix[i + 1] = make_pair(i + 1, pre[i]);
  }
  int ans = 0;
  vector<pair<int, int> > ansv;
  for (int i = 1; i <= n; i++) {
    int L = i - d1[i - 1];
    int R = i + d1[i - 1];
    int len = min(prefix[L].second, n - R + 1);
    int tans = 2 * len + R - L - 1;
    if (tans > ans) {
      ans = tans;
      ansv.clear();
      ansv.push_back(make_pair(prefix[L].first - len + 1, len));
      ansv.push_back(make_pair(L + 1, R - L - 1));
      ansv.push_back(make_pair(n - len + 1, len));
    }
  }
  int cnt = ansv[0].second == 0 ? 1 : 3;
  cout << cnt << endl;
  for (int i = 0; i < 3; i++) {
    if (ansv[i].second == 0) continue;
    cout << ansv[i].first << " " << ansv[i].second << endl;
  }
}
