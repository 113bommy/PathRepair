#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int dp[2][76][76][76];
vector<int> v, k, x;
int rec(int i, int j, int h, int z) {
  if (i + j + h == n) return 0;
  if (dp[z][i][j][h] != -1) return dp[z][i][j][h];
  int an = 1e7;
  if (!z && j < k.size()) {
    int cnt = 0;
    for (int g = i; g < v.size() && v[g] < k[j]; g++) cnt++;
    for (int g = h; g < x.size() && x[g] < k[j]; g++) cnt++;
    an = min(an, rec(i, j + 1, h, 0) + cnt);
  }
  int cnt = 0;
  if (h < x.size()) {
    for (int g = i; g < v.size() && v[g] < x[h]; g++) cnt++;
    for (int g = j; g < k.size() && k[g] < x[h]; g++) cnt++;
    an = min(an, rec(i, j, h + 1, 0) + cnt);
  }
  cnt = 0;
  if (i < v.size()) {
    for (int g = h; g < x.size() && x[g] < v[i]; g++) cnt++;
    for (int g = j; g < k.size() && k[g] < v[i]; g++) cnt++;
    an = min(an, rec(i + 1, j, h, 1) + cnt);
  }
  return dp[z][i][j][h] = an;
}
int main() {
  memset(dp, -1, sizeof dp);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cin >> s;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == 'V')
      v.push_back(i);
    else if (s[i - 1] == 'K')
      k.push_back(i);
    else
      x.push_back(i);
  }
  cout << rec(0, 0, 0, 0) << '\n';
  return 0;
}
