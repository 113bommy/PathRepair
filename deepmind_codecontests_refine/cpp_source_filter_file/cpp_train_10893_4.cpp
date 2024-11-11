#include <bits/stdc++.h>
using namespace std;
int hsh[26];
int valid[26];
int pw[10];
int sm[26];
int dinc;
int dp[26][1 << 12];
int go(int idx, int mask) {
  if (idx == 26) {
    int dif = 0;
    for (int j = 0; j < 26; ++j) dif += hsh[j];
    for (int j = 0; j < 10; ++j)
      if (1 << j & mask) --dif;
    if (dif == 0) return 0;
    return 1e8;
  }
  if (dp[idx][mask] != -1) return dp[idx][mask];
  if (hsh[idx] == 0) return go(idx + 1, mask);
  int res = 1e8;
  for (int j = 0; j < dinc; ++j) {
    if (mask & 1 << j) continue;
    if (valid[idx] && j == 0) continue;
    res = min(res, sm[idx] * j + go(idx + 1, mask | 1 << j));
  }
  return dp[idx][mask] = res;
}
int main() {
  memset(dp, -1, sizeof dp);
  pw[0] = 1;
  for (int i = 1; i <= 6; ++i) pw[i] = 10 * pw[i - 1];
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    for (int j = 0; j < x.size(); ++j) {
      hsh[x[j] - 'a'] = 1;
      int len = x.size() - j - 1;
      sm[x[j] - 'a'] += pw[len];
      if (j == 0) valid[x[j] - 'a'] = 1;
    }
  }
  dinc = 10;
  cout << go(0, 0);
}
