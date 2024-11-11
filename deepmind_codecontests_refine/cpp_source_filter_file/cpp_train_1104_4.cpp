#include <bits/stdc++.h>
using namespace std;
long long dp[15][2048][70];
inline void get_dp() {
  for (int b = 2; b <= 10; b++) {
    dp[b][0][0] = 1;
    for (int len = 1; len < 70; len++)
      for (int mask = 0; mask <= (1 << b); mask++)
        for (int num = 0; num < b; num++)
          dp[b][mask][len] += dp[b][mask ^ (1 << num)][len - 1];
  }
}
inline string to_s(int x, int b) {
  string ans;
  while (x > 0) {
    ans += char('0' + x % b);
    x /= b;
  }
  reverse(ans.begin(), ans.end());
  if (ans.empty()) ans = "0";
  return ans;
}
inline long long k_less(int b, string x) {
  int len = x.size();
  long long k = 0;
  for (int i = 1; i < len - 1; i++)
    for (int num = 1; num < b; num++) k += dp[b][1 << num][i];
  int mask = 0;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < x[i] - '0'; j++) {
      if ((i == 0) && (j == 0)) continue;
      int cur = mask ^ (1 << j);
      k += dp[b][cur][len - i - 1];
    }
    mask ^= (1 << (x[i] - '0'));
  }
  return k;
}
inline long long get_ans(int b, string l, string r) {
  return (k_less(b, r) - k_less(b, l));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  get_dp();
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int b;
    long long l, r;
    cin >> b >> l >> r;
    r++;
    cout << get_ans(b, to_s(l, b), to_s(r, b)) << "\n";
  }
  return 0;
}
