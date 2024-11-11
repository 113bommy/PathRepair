#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int last[26];
int dp[1 << 20];
int L[maxn];
string s;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  memset(last, -1, sizeof last);
  cin >> s;
  for (int i = 0; i < (int)s.size(); i++) {
    int x = s[i] - 'a';
    int state = 0;
    if (i == 0)
      L[i] = 0;
    else
      L[i] = max(L[i - 1], last[x] + 1);
    for (int j = i; j >= L[i]; j--) {
      state |= 1 << (s[j] - 'a');
      dp[state] = i - j + 1;
    }
    last[x] = i;
  }
  for (int i = 0; i < 20; i++)
    for (int j = 0; j < (1 << 20); j++)
      if (j & (1 << i)) dp[j] = max(dp[j], dp[j ^ (1 << i)]);
  int ans = 0, N = (1 << 20) - 1;
  for (int i = 0; i < (int)s.size(); i++) {
    int x = s[i] - 'a';
    int state = 0;
    for (int j = i; j >= L[i]; j--) {
      state |= 1 << (s[j] - 'a');
      ans = max(ans, i - j + 1 + dp[N ^ state]);
    }
  }
  cout << ans << "\n";
  return 0;
}
