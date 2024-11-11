#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long large = 2000000000000000000LL;
int f[200010];
vector<int> cnt;
int n, m, k;
void solve(int c) {
  memset(f, 0, k);
  f[0] = 1;
  for (int i = 0; i < c; i++) {
    for (int j = k; j >= cnt[i]; j--) {
      f[j] |= f[j - cnt[i]];
    }
  }
}
int main() {
  int testcase;
  cin >> testcase;
  while (testcase--) {
    scanf("%d%d%d", &n, &m, &k);
    string s;
    cin >> s;
    cnt.assign(26, 0);
    for (int i = 0; i < (int)s.length(); i++) {
      cnt[(int)(s[i] - 'A')]++;
    }
    solve(26);
    bool can = false;
    for (int i = n; i <= k; i++) {
      if (f[i]) {
        int re = k - i;
        if (re >= m) {
          can = true;
          break;
        }
      }
    }
    if (can) {
      cout << 0 << endl;
      continue;
    }
    int ans = 1000000000;
    for (int i = 0; i < 26; i++) {
      swap(cnt[i], cnt[25]);
      solve(25);
      int sum = -1;
      for (int i = n - 1; i >= 0; i--) {
        if (f[i]) {
          if (i + cnt[25] > n) {
            ans = min(ans, (n - i) * max(m - (k - i - cnt[25]), 0));
          }
        }
      }
      if (sum != -1) {
      }
      swap(cnt[i], cnt[25]);
    }
    cout << ans << endl;
  }
  return 0;
}
