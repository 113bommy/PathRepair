#include <bits/stdc++.h>
using namespace std;
const int b = 10;
const int maxl = 60;
const int maxn = 1 << 10;
long long dp[b + 2][maxl + 10][maxn + 100], cnt[b + 2][maxl + 100];
long long solve(int base, long long lmt) {
  vector<int> tmp;
  while (lmt) {
    tmp.push_back(lmt % base);
    lmt /= base;
  }
  reverse(tmp.begin(), tmp.end());
  int sz = tmp.size();
  long long ans = 0;
  if (sz) {
    ans += cnt[base][sz - 1];
  }
  long long mask = 0;
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < tmp[i]; j++) {
      if (i == 0 && j == 0) continue;
      ans += dp[base][sz - 1 - i][mask ^ (1 << j)];
    }
    mask ^= (1 << tmp[i]);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 2; i <= b; i++) {
    dp[i][0][0] = 1;
    for (int j = 1; j <= maxl; j++) {
      for (int k = 0; k < (1 << i); k++) {
        for (int l = 0; l < i; l++) {
          dp[i][j][k] += dp[i][j - 1][k ^ (1 << l)];
        }
      }
      cnt[i][j] = cnt[i][j - 1];
      for (int k = 1; k < i; k++) {
        cnt[i][j] += dp[i][j - 1][1 << k];
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int base;
    long long l, r;
    cin >> base >> l >> r;
    long long ans = solve(base, r + 1) - solve(base, l);
    cout << ans << "\n";
  }
}
