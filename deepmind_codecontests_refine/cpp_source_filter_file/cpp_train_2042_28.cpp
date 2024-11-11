#include <bits/stdc++.h>
using namespace std;
int n, a;
long long x, y, cnt[1000006], sum[1000006], ans = 1e18;
int main() {
  cin >> n >> y >> x;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    cnt[a]++, sum[a] += a;
  }
  for (int i = 1; i <= 1e6; i++) cnt[i] += cnt[i - 1], sum[i] += sum[i - 1];
  for (int i = 2; i <= 1e6; i++) {
    long long temp = 0;
    for (int j = i; j <= 1e6; j += i) {
      int l = j - i + 1, r = j - 1;
      int m = max(j - y / x - 1, (long long)l - 1);
      temp += (cnt[m] - cnt[l - 1]) * y +
              x * (j * (cnt[r] - cnt[m]) - (sum[r] - sum[m]));
    }
    ans = min(ans, temp);
  }
  cout << ans;
  return 0;
}
