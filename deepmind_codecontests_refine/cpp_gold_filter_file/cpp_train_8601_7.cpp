#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1e9, MOD = 1e9 + 7, MAXN = 105, MAXA = 1e5 + 5;
const long double EPS = 1e-9, PI = acos(-1);
vector<int64_t> ten(20);
int64_t create_number(int64_t num, int64_t len) {
  int64_t ans = 0;
  for (int64_t i = 0; i < len; ++i) {
    int64_t digit = (num / ten[i]) % 10;
    ans += digit * (ten[len + i] + ten[len - i - 1]);
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int64_t k, p;
  cin >> k >> p;
  ten[0] = 1;
  for (int64_t i = 1; i < 20; ++i) ten[i] = (ten[i - 1] * 10) % p;
  int64_t ans = 0, now = 1;
  for (int64_t i = 1; i <= k; ++i) {
    if (i == ten[now]) now++;
    ans += create_number(i, now) % p;
    ans %= p;
  }
  cout << ans << endl;
  return 0;
}
