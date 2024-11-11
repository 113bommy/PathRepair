#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, p, q, r;
  cin >> n >> p >> q >> r;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long minL[n], minR[n], maxL[n], maxR[n];
  minL[0] = a[0];
  maxL[0] = a[0];
  for (long long i = 1; i < n; i++) {
    minL[i] = min(minL[i - 1], a[i]);
    maxL[i] = max(maxL[i - 1], a[i]);
  }
  minR[n - 1] = a[n - 1];
  maxR[n - 1] = a[n - 1];
  for (long long i = n - 2; i >= 0; i--) {
    minR[i] = min(minR[i + 1], a[i]);
    maxR[i] = max(maxR[i + 1], a[i]);
  }
  long long ans1 = INT_MIN;
  for (long long i = 0; i < n; i++) {
    long long ans = 0;
    ans += a[i] * q;
    if (p > 0) {
      ans += p * maxL[i];
    } else {
      ans += p * minL[i];
    }
    if (r > 0) {
      ans += r * maxR[i];
    } else {
      ans += r * minR[i];
    }
    ans1 = max(ans1, ans);
  }
  cout << ans1 << endl;
  return 0;
}
