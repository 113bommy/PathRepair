#include <bits/stdc++.h>
using namespace std;
const long long int N = 500005;
long long int a[N], n, r, k;
long long int cnt[N];
long long int pre[N];
inline bool check(long long int val) {
  long long int lft = k;
  for (long long int i = 0; i <= n; i++) pre[i] = 0;
  for (long long int i = 1 + r; i <= n; i++) {
    long long int done = pre[i - 1] - pre[max(i - 2 * r - 1, 0LL)];
    pre[i] = pre[i - 1];
    if (cnt[i - r] + done < val) {
      if (lft > (val - cnt[i - r] - done))
        lft -= (val - cnt[i - r] - done), pre[i] += (val - cnt[i - r] - done);
      else
        return 0;
    }
  }
  for (long long int i = n - r + 1; i <= n; i++) {
    long long int done = pre[n] - pre[max(i - r - 1, 0LL)];
    if (cnt[i] + done < val) {
      if (lft > (val - cnt[i] - done))
        pre[n] += (val - cnt[i] - done), lft -= (val - cnt[i] - done);
      else
        return 0;
    }
  }
  if (lft >= 0)
    return 1;
  else
    return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n >> r >> k;
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[max(i - r, 1LL)] += a[i];
    cnt[min(i + r, n) + 1] -= a[i];
  }
  for (long long int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
  long long int s = 0, e = 4 * 1000000000000000007, mid;
  long long int ans = 0;
  while (s <= e) {
    mid = (s + e) / 2;
    if (check(mid))
      ans = mid, s = mid + 1;
    else
      e = mid - 1;
  }
  cout << ans;
}
