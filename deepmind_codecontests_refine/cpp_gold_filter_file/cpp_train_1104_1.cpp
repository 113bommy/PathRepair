#include <bits/stdc++.h>
using namespace std;
const int B = 11;
const int N = 61;
const long long inf = 1e18;
long long dp[B][N][1 << (B - 1)];
void pre() {
  for (int b = 2; b < B; ++b) {
    unsigned long long h = 1;
    dp[b][0][0] = 1;
    for (int w = 1; h <= inf; ++w, h *= b) {
      for (int s = 0; s < (1 << b); ++s) {
        for (int d = 0; d < b; ++d) {
          dp[b][w][s] += dp[b][w - 1][1 << d ^ s];
        }
      }
    }
  }
}
long long calc(int b, long long v) {
  if (!v) return 0;
  string u;
  for (; v; v /= b) u += char(v % b);
  reverse(begin(u), end(u));
  long long ans = 0;
  for (int i = 2; i < ((int)((u).size())); i += 2)
    ans += dp[b][i][0] - dp[b][i - 1][1];
  int s = 0;
  for (int i = 0; i < ((int)((u).size())); ++i) {
    for (int j = !i; j < u[i]; ++j)
      ans += dp[b][((int)((u).size())) - i - 1][1 << j ^ s];
    s ^= 1 << u[i];
  }
  return ans + !s;
}
int main() {
  pre();
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int b;
    long long l, r;
    cin >> b >> l >> r;
    cout << calc(b, r) - calc(b, l - 1) << '\n';
  }
}
