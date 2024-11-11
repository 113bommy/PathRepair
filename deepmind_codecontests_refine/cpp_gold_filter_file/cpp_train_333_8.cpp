#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n, k, a[N];
long long pre[N], precnt[N];
int b[N], now, num = 1;
long long cnt[N];
long long cal(long long val, int x) {
  if (cnt[x] >= k) return 0;
  int res = k - cnt[x];
  long long q1 = precnt[x - 1] * (val - 1) - pre[x - 1];
  long long q2 = pre[now] - pre[x] - (precnt[now] - precnt[x]) * (val + 1);
  long long ans1 = 0, ans2 = 0, ans3 = 0;
  if (precnt[x - 1] >= res)
    ans1 = q1 + res;
  else
    ans1 = 1e18;
  if (precnt[now] - precnt[x] >= res)
    ans2 = q2 + res;
  else
    ans2 = 1e18;
  ans3 = q1 + q2 + res;
  ans1 = min(ans1, ans2);
  ans1 = min(ans1, ans3);
  return ans1;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[i + 1]) {
      now++;
      b[now] = a[i];
      cnt[now] = num;
      num = 1;
    } else
      num++;
  }
  for (int i = 1; i <= now; i++)
    pre[i] = pre[i - 1] + b[i] * cnt[i], precnt[i] = precnt[i - 1] + cnt[i];
  long long ans = 1e18;
  for (int i = 1; i <= now; i++) {
    ans = min(ans, cal(b[i], i));
  }
  cout << ans << endl;
  return 0;
}
