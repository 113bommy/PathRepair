#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 1e6 + 10;
const int maxn5 = 5e6 + 10;
const int maxnt = 1.2e6 + 10;
const int maxn3 = 1e3 + 10;
const int mod = 5e8;
const int ssq = 460;
const long long alp = 64;
const long long inf = 2e18;
int dp[maxn5];
long long now, tav, modh, pre[maxn5];
int get_val(char a) {
  if (a >= 'a' && a <= 'z') return a - 'a' + 1;
  if (a >= 'A' && a <= 'Z') return a - 'A' + 1 + 26;
  return a - '0' + 1 + 52;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  modh = 1023456789;
  pre[0] = get_val(s[0]);
  tav = 1;
  for (int i = 1; i < n; i++) {
    tav *= alp;
    tav %= modh;
    long long val = get_val(s[i]);
    pre[i] = pre[i - 1] + (tav * val);
    pre[i] %= modh;
  }
  dp[0] = 1;
  long long ans = 1;
  int last = 1;
  tav = 1;
  now = 0;
  for (int i = 1; i < n; i++) {
    long long val = get_val(s[i]), val2 = get_val(s[last]);
    if (i % 2 == 1) {
      now *= alp;
      now += val;
      now %= modh;
      if (i > 1) {
        tav *= alp;
        tav %= modh;
      }
    } else {
      last++;
      now = (modh + now - (tav * val2) % modh) % modh;
      now *= alp;
      now += val;
      now %= modh;
    }
    if (now == pre[(i + 1) / 2 - 1]) dp[i] = dp[(i + 1) / 2 - 1] + 1;
    ans += dp[i];
  }
  cout << ans << '\n';
}
