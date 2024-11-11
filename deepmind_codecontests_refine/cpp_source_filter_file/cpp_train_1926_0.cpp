#include <bits/stdc++.h>
using namespace std;
const int maxn = 70 + 10;
const long long MO = 1e9 + 7;
const long long IN = 1e9;
map<string, string> mp;
vector<pair<int, string>> v1[maxn];
long long dp[maxn][maxn];
long long ans = 0;
int n, k;
void dp_add(int a, int b, int x, int y, long long val) {
  int l = a, r = a + 2 * b - 1;
  if (r > 2 * n || y > 2 * n) return;
  for (auto f : v1[x]) {
    int pos = f.first;
    string sign = f.second;
    if (sign == "=") {
      if (pos != x && pos != y) return;
      continue;
    }
    if (sign == ">") {
      if (pos >= l && pos <= r) return;
      continue;
    }
    if (sign == "<") {
      if (pos == x || pos == y || pos > r || pos < l) return;
      continue;
    }
    if (sign == "<=") {
      if (pos > r || pos < l) return;
      continue;
    }
    if (sign == ">=") {
      if (pos >= l && pos <= r && pos != x && pos != y) return;
      continue;
    }
  }
  for (auto f : v1[y]) {
    int pos = f.first;
    string sign = f.second;
    if (sign == "=") {
      if (pos != x && pos != y) return;
      continue;
    }
    if (sign == ">") {
      if (pos >= l && pos <= r) return;
      continue;
    }
    if (sign == "<") {
      if (pos == x || pos == y || pos > r || pos < l) return;
      continue;
    }
    if (sign == "<=") {
      if (pos > r || pos < l) return;
      continue;
    }
    if (sign == ">=") {
      if (pos >= l && pos <= r && pos != x && pos != y) return;
      continue;
    }
  }
  dp[b][a] += val;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  mp["="] = "=";
  mp[">"] = "<";
  mp["<"] = ">";
  mp[">="] = "<=";
  mp["<="] = ">=";
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    string sign;
    cin >> x >> sign >> y;
    v1[x].push_back(make_pair(y, sign));
    v1[y].push_back(make_pair(x, mp[sign]));
  }
  for (int i = 1; i < 2 * n; i++) {
    memset(dp, 0, sizeof dp);
    dp_add(i, 1, i, i + 1, 1);
    for (int t = 1; t < n; t++)
      for (int j = 1; j <= 2 * n; j++) {
        dp_add(j, t + 1, j, j + 1, dp[t][j + 2]);
        dp_add(j, t + 1, j, j + 2 * t + 1, dp[t][j + 1]);
        dp_add(j, t + 1, j + 2 * t + 1, j + 2 * t + 2, dp[t][j]);
      }
    ans += dp[n][1];
  }
  cout << ans << "\n";
}
