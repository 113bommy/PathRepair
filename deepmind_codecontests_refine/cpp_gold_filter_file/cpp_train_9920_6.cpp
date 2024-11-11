#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int n, a[maxn], freq[maxn], presum[2 * maxn];
int solve1(int d, int v) {
  presum[maxn] = -1;
  int ans = 0;
  int sum = 0;
  int minsum = 0, maxsum = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == d) sum++;
    if (a[i] == v) sum--;
    if (sum >= minsum && sum <= maxsum) {
      ans = max(ans, i - presum[sum + maxn]);
    } else
      presum[sum + maxn] = i;
    minsum = min(minsum, sum);
    maxsum = max(maxsum, sum);
  }
  return ans;
}
int solve2(int lim) {
  memset(freq, 0, sizeof freq);
  int ans = 0;
  int eql = 0;
  for (int i = 0, j = 0; i < n; i++) {
    if (++freq[a[i]] == lim) eql++;
    while (freq[a[i]] > lim && j <= i) {
      if (freq[a[j++]]-- == lim) eql--;
    }
    if (eql >= 2) ans = max(ans, i - j + 1);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int ans = 0;
  cin >> n;
  int d = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    freq[a[i]] += 1;
    if (freq[d] < freq[a[i]]) d = a[i];
  }
  int up = sqrt(n);
  for (int i = 1; i <= n; i++) {
    if (d != i && freq[i] >= up) ans = max(ans, solve1(d, i));
  }
  for (int i = 1; i < up; i++) {
    ans = max(ans, solve2(i));
  }
  cout << ans;
  return 0;
}
