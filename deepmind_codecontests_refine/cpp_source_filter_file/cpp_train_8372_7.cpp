#include <bits/stdc++.h>
using namespace std;
char z[1000100];
string s;
long long dp[1000100][6], n;
int state(int i, int stage) {
  if (stage == 6) return 1;
  if (i == n) return 0;
  if (dp[i][stage] != -1) return dp[i][stage];
  long long ans = 0;
  if (stage == 0) {
    ans += state(i + 1, stage);
    if (s[i] >= 'a' && s[i] <= 'z')
      ans += state(i + 1, stage + 1) + state(i + 1, stage + 2);
  }
  if (stage == 1) {
    if (s[i] != '.' && s[i] != '@')
      ans += state(i + 1, stage + 1) + state(i + 1, stage);
  }
  if (stage == 2) {
    if (s[i] == '@') ans += state(i + 1, stage + 1);
  }
  if (stage == 3) {
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
      ans += state(i + 1, stage + 1) + state(i + 1, stage);
  }
  if (stage == 4) {
    if (s[i] == '.') ans += state(i + 1, stage + 1);
  }
  if (stage == 5) {
    if (s[i] >= 'a' && s[i] <= 'z')
      ans += state(i + 1, stage + 1) + state(i + 1, stage);
  }
  return dp[i][stage] = ans;
}
int main() {
  scanf("%s", z);
  s = string(z);
  n = s.size();
  memset(dp, -1, sizeof dp);
  cout << state(0, 0);
  return 0;
}
