#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e+5;
int cnt[maxn], sum[maxn];
int n, k, q, l, r;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(cnt, 0, sizeof(cnt));
  memset(sum, 0, sizeof(sum));
  cin >> n >> k >> q;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    cnt[l]++;
    cnt[r + 1]--;
  }
  int num = 0;
  for (int i = 1; i < maxn; i++) {
    num += cnt[i];
    sum[i] = sum[i - 1] + (num >= k ? 1 : 0);
  }
  for (int i = 0; i < q; i++) {
    cin >> l >> r;
    cout << sum[r] - sum[l - 1] << '\n';
  }
  return 0;
}
