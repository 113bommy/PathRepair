#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
int dp[10010][5], n;
string s;
string get(int a, int b) { return string(s.begin() + a, s.begin() + b); }
int solve(int i, int len) {
  if (i + len > n) return 0;
  if (i + len == n) return 1;
  int &re = dp[i][len];
  if (re != -1) return re;
  for (int j = 2; j < 4; j++) {
    int c = solve(i + len, j);
    string s = get(i, i + j);
    string t = get(i + len, i + len + j);
    if (c && s != t) return re = 1;
  }
  return re = 0;
}
int main() {
  cin >> s;
  n = (int)s.size();
  set<string> ss;
  memset(dp, -1, sizeof(dp));
  for (int i = 5; i < n; i++)
    for (int j = 2; j < 4; j++)
      if (solve(i, j)) ss.insert(get(i, i + j));
  cout << (int)ss.size() << endl;
  for (auto i : ss) cout << i << endl;
  return 0;
}
