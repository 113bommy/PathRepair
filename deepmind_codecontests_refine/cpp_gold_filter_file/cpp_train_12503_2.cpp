#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
long long a[maxn], sum[maxn], cnt[maxn], c[maxn], n, t;
int lowbit(int x) { return x & (-x); }
void update(int pos, long long x) {
  while (pos <= n + 1) {
    c[pos] += x;
    pos += lowbit(pos);
  }
}
long long getSum(int pos) {
  long long sum = 0;
  while (pos > 0) {
    sum += c[pos];
    pos -= lowbit(pos);
  }
  return sum;
}
int main() {
  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
    cnt[i] = sum[i];
  }
  sort(cnt, cnt + 1 + n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int pos = lower_bound(cnt, cnt + n + 1, sum[i - 1]) - cnt + 1;
    update(pos, 1);
    pos = lower_bound(cnt, cnt + n + 1, sum[i] - t + 1) - cnt;
    ans += (i - getSum(pos));
  }
  cout << ans << endl;
  return 0;
}
