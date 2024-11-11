#include <bits/stdc++.h>
using namespace std;
int tavan(int a, int n, int mod) {
  int res = 1;
  while (n) res *= (n & 1) ? a : 1, res %= mod, n /= 2, a *= a, a %= mod;
  return res;
}
const int MOD = ((int)81671);
const int N = ((int)40);
const int M = ((int)12);
const int X = ((int)2e6);
int n, m, p[M];
string s[M], now;
bool mark[X];
vector<string> v;
void solve(int pos, int x) {
  if (x < 0) return;
  if (pos == (int)s[0].size() && x != 0) return;
  if (x == 0) {
    for (int i = pos; i < s[0].size(); i++)
      now[i] = (s[0][pos] == '0') ? '1' : '0';
    v.push_back(now);
    return;
  }
  now[pos] = s[0][pos];
  solve(pos + 1, x - 1);
  now[pos] = (s[0][pos] == '0') ? '1' : '0';
  solve(pos + 1, x);
  now[pos] = s[0][pos];
}
int main() {
  cin >> n >> m >> s[0] >> p[0];
  now = s[0];
  solve(0, p[0]);
  int ans = v.size();
  for (int i = 1; i < m; i++) {
    cin >> s[i] >> p[i];
    for (int j = 0; j < v.size(); j++)
      if (!mark[j]) {
        int num = 0;
        for (int k = 0; k < v[j].size(); k++)
          if (v[j][k] == s[i][k]) num++;
        if (num != p[i]) mark[j] = 1, ans--;
      }
  }
  cout << ans;
  return 0;
}
