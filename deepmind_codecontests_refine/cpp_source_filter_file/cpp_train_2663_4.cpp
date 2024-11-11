#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
string s;
int q2 = 0;
long long int memo[1000 + 10];
vector<int> let(26);
long long int dp(int u) {
  if (u >= ((int)(s).size())) return 1;
  if (memo[u] != -1) return memo[u];
  long long int& res = memo[u];
  res = dp(u + 1);
  res = res % MOD;
  char ch = s[u] - 'a';
  int len = let[ch];
  for (int v = (int)(u + 1); v < (int)(((int)(s).size())); v++) {
    ch = s[v] - 'a';
    len = min(len, let[ch]);
    if (len >= v + 1 - u) {
      q2 = max(q2, v + 1 - u);
      res += dp(v + 1);
      res = res % MOD;
    } else
      return res;
  }
  return res;
}
int solveq3() {
  int q3 = 1;
  int u = 0;
  while (u < ((int)(s).size()) - 1) {
    char ch = s[u] - 'a';
    int len = let[ch];
    int v = u + 1;
    while (v < ((int)(s).size()) && u < v) {
      ch = s[v] - 'a';
      len = min(len, let[ch]);
      if (len < v + 1 - u) {
        u = v;
        q3++;
      } else
        v++;
    }
    if (v == ((int)(s).size())) u++;
  }
  return q3;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n >> s;
  fill(memo, memo + n + 1, (long long int)-1);
  for (int i = 0; i < int(26); i++) cin >> let[i];
  long long int q1 = dp(0);
  cout << q1 << " " << q2 << " " << solveq3() << '\n';
  return 0;
}
