#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e6 + 10, MAXM = 2e7 + 10;
const int INF = INT_MAX, SINF = 0x3f3f3f3f;
const long long llINF = LLONG_MAX;
const int MOD = 1e9 + 7, mod = 998244353;
long long f[MAXN], n, d;
long long calc(int n) {
  long long ans = 0;
  for (int i = 0; n; i++) {
    ans += i * min((1 << i), n);
    n -= min((1 << i), n);
  }
  return ans;
}
int num[5005], cur, ans[5005], cnt[5005];
vector<int> v[5005];
int solve() {
  memset(cnt, 0, sizeof(cnt));
  scanf("%lld%lld", &n, &d);
  if (d < calc(n)) return puts("NO"), 0;
  if (d > n * (n - 1) / 2) return puts("NO"), 0;
  puts("YES");
  for (int i = 1; i <= n; i++) f[i] = i - 1, num[i - 1] = 1;
  for (int i = 0; i <= n; i++) v[i].resize(0);
  int ansnow = n * (n - 1) / 2 - d;
  for (int i = n; i; i--) {
    for (int j = 0; j < i; j++) {
      if (num[j] < (1 << j) && ansnow >= i - j - 1) {
        ansnow -= (i - j - 1);
        f[i] = j;
        num[j]++;
        num[i - 1]--;
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) v[f[i]].push_back(i);
  for (int i = 1; i <= n; i++) {
    for (auto j : v[i]) {
      ans[j] = v[i - 1][cnt[i - 1] / 2];
      cnt[i - 1]++;
    }
  }
  for (int i = 2; i <= n; i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
