#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
const int logA = 29;
const int MOD = 1e9 + 7;
int n, m, a[N];
int cntBit[logA + 1][N];
void init() {
  sort(a + 1, a + 1 + n);
  for (int bit = 0; bit <= logA; bit++)
    for (int i = 1; i <= n; i++)
      cntBit[bit][i] = cntBit[bit][i - 1] + ((a[i] & (1 << bit)) ? 1 : 0);
}
int calcCnt(int l, int r) {
  l = lower_bound(a + 1, a + 1 + n, l) - a;
  r = upper_bound(a + 1, a + 1 + n, r) - a - 1;
  if (l > r) return 0;
  return r - l + 1;
}
int calcSum(int l, int r, int x, int t) {
  l = lower_bound(a + 1, a + 1 + n, l) - a;
  r = upper_bound(a + 1, a + 1 + n, r) - a - 1;
  if (l > r) return 0;
  int len = r - l + 1;
  int ans = 0;
  for (int bit = 0; bit <= t; bit++)
    if (x & (1 << bit))
      ans = ((long long)ans +
             (long long)(1 << bit) *
                 (long long)(len - (cntBit[bit][r] - cntBit[bit][l - 1]))) %
            MOD;
    else
      ans = ((long long)ans +
             (long long)(1 << bit) *
                 (long long)(cntBit[bit][r] - cntBit[bit][l - 1])) %
            MOD;
  return ans;
}
int trau() {
  vector<int> x;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) x.push_back(a[i] ^ a[j]);
  sort(x.begin(), x.end(), greater<int>());
  int ans = 0;
  for (int i = 0; i <= m - 1; i++) ans = (ans + x[i]) % MOD;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  init();
  int cur = 0, tmp = 0, ans = 0;
  for (int bit = logA; bit >= 0; bit--) {
    cur = cur ^ (1 << bit);
    tmp = tmp ^ (1 << bit);
    int cnt = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      int l = (a[i] ^ cur) & tmp;
      if (l < a[i]) continue;
      int r = (a[i] ^ cur) | ((1 << bit) - 1);
      cnt += calcCnt(l, r);
      sum = (sum + calcSum(l, r, a[i], bit));
    }
    if (m >= cnt) {
      m -= cnt;
      ans = (ans + sum) % MOD;
      cur = cur ^ (1 << bit);
    } else {
      ans = ((long long)ans + (long long)m * (1 << bit)) % MOD;
    }
  }
  cout << ans;
  return 0;
}
