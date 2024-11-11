#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 41;
vector<int> kmp;
string s;
void prefix_function() {
  for (int i = 1; i < (int)s.size(); ++i) {
    int j = kmp[i - 1];
    while (j > 0 && s[j] != s[i]) {
      j = kmp[j - 1];
    }
    if (s[j] == s[i]) j++;
    kmp[i] = j;
  }
}
int goKmp(int st, char c) {
  if (st == (int)s.size()) st = kmp[st - 1];
  while (st > 0 && s[st] != c) {
    st = kmp[st - 1];
  }
  if (s[st] == c) st++;
  return st;
}
long long dp[N][N][N][2];
int fnd(int len, int v, int en, int good) {
  long long& ans = dp[len][v][en][good];
  if (ans != -1) {
    return ans;
  }
  if (v == (int)s.size()) good = true;
  if (len == 0) {
    ans = ((v == en) and good);
    return ans;
  }
  ans = 0;
  for (int i = 0; i < 2; ++i) {
    ans += fnd(len - 1, goKmp(v, i + '0'), en, good);
  }
  return ans;
}
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> s;
  kmp.resize((int)s.size());
  prefix_function();
  memset(dp, -1, sizeof(dp));
  long long ans = 0;
  for (int i = 0; i <= (int)s.size(); ++i) {
    ans += fnd(n, i, i, 0);
  }
  cout << ans << endl;
  return 0;
}
