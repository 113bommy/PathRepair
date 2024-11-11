#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const long long mod = 1e9 + 7;
string fString[35];
void precalcStrings() {
  fString[1] = "a";
  fString[2] = "b";
  for (int i = 3; i <= 30; i++) {
    fString[i] = fString[i - 1] + fString[i - 2];
  }
}
int match(string s, string pattern) {
  vector<int> f;
  f.assign(pattern.size() + 1, 0);
  int len = 0;
  f[0] = 0;
  for (int i = 1; i < pattern.size(); i++) {
    if (pattern[len] == pattern[i]) {
      len++;
      f[i] = len;
    } else {
      while (pattern[len] != pattern[i] && len != 0) len = f[len - 1];
      if (pattern[len] == pattern[i]) {
        len++;
        f[i] = len;
      } else {
        f[i] = 0;
      }
    }
  }
  len = 0;
  int answer = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == pattern[len]) {
      len++;
      if (len == pattern.size()) {
        answer++;
        len = f[pattern.size() - 1];
      }
    } else {
      while (s[i] != pattern[len] && len != 0) len = f[len - 1];
      if (s[i] == pattern[len]) {
        len++;
      } else {
        len = 0;
      }
    }
  }
  return answer;
}
string getPrefix(string s, int len) {
  string out = "";
  for (int i = 0; i < len; i++) out += s[i];
  return out;
}
string getSuffix(string s, int len) {
  string out = "";
  for (int i = s.size() - len; i < s.size(); i++) out += s[i];
  return out;
}
long long k;
string s;
int val[2];
string prefix;
string suffix[2];
long long dp[MAXN];
void solve() {
  if (k < 30) {
    cout << match(fString[k], s) << '\n';
    return;
  }
  int n = s.size();
  int ind;
  for (int i = 1; i < 30; i++) {
    if (fString[i].size() > s.size()) {
      ind = i;
      break;
    }
  }
  prefix = getPrefix(fString[ind], n - 1);
  suffix[0] = getSuffix(fString[ind], n - 1);
  suffix[1] = getSuffix(fString[ind + 1], n - 1);
  val[0] = match(suffix[0] + prefix, s);
  val[1] = match(suffix[1] + prefix, s);
  dp[ind] = match(fString[ind], s);
  dp[ind + 1] = match(fString[ind + 1], s);
  for (int i = ind + 2; i <= k; i++) {
    int type = ((i - 1) % 2) ^ (ind % 2);
    dp[i] = (dp[i - 2] + dp[i - 1] + val[type]);
  }
  cout << dp[k] << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  precalcStrings();
  int T;
  cin >> k >> T;
  while (T--) {
    cin >> s;
    solve();
  }
}
