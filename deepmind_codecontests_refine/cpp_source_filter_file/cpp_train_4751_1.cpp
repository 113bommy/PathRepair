#include <bits/stdc++.h>
using namespace std;
const int M = 4000010, mod = 1000000007;
int cnt[M];
int main() {
  ios_base::sync_with_stdio(false);
  int n, m, i, j, k;
  int ans = 0;
  scanf("%d%d%d", &n, &m, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &j);
    cnt[j + 1000005]++;
  }
  k--;
  int sum = 0;
  for (i = 0, j = m; i < M; i++, j++) {
    sum += (cnt[j] - cnt[i]);
    if (sum > k) {
      cnt[j] -= (sum - k);
      ans += (sum - k);
      sum -= (sum - k);
    }
  }
  printf("%d\n", ans);
  return 0;
}
