#include <bits/stdc++.h>
using namespace std;
long long n, x, y, ans;
long long fr[2000005];
long long s[2000005];
long long cnt(long long mini, long long maxi) {
  if (maxi < mini) return 0;
  if (fr[maxi] - fr[mini - 1] < 0) {
    cout << mini << ' ' << maxi << '\n';
    exit(0);
  }
  return fr[maxi] - fr[mini - 1];
}
long long sum(long long mini, long long maxi) {
  if (maxi < mini) return 0;
  if (s[maxi] - s[mini - 1] < 0) {
    cout << mini << ' ' << maxi << '\n';
    exit(0);
  }
  return s[maxi] - s[mini - 1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    fr[x]++;
    s[x] += x;
  }
  for (int i = 1; i <= 2e6 + 1; i++) {
    fr[i] += fr[i - 1];
    s[i] += s[i - 1];
  }
  ans = 1e18;
  for (long long g = 2; g <= 1e6; g++) {
    long long nans = 0;
    long long f = min(x / y, g - 1);
    for (long long k = g; k <= 2e6; k += g) {
      nans += cnt(k - g + 1, k - f - 1) * x;
      nans += (cnt(k - f, k) * k - sum(k - f, k)) * y;
    }
    if (nans < 0) {
      cout << g << ' ' << nans << '\n';
      return 0;
    }
    ans = min(ans, nans);
  }
  cout << ans;
  return 0;
}
