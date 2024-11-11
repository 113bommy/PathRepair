#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  vector<long long> x(n);
  for (long long i = 0; i < n; i++) cin >> x[i];
  sort(x.begin(), x.end());
  vector<long long> pre(n);
  pre[0] = x[0];
  for (long long i = 0; i < n; i++) pre[i] = pre[i - 1] + x[i];
  long long ans = 1;
  long long ans2 = x[0];
  for (int i = 1; i < n; i++) {
    long long l = 0;
    long long h = i - 1;
    while (l <= h) {
      long long mid = l + (h - l) / 2;
      long long cnt = i - mid;
      if ((x[i] * cnt - (pre[i - 1] - pre[mid] + x[mid])) <= k)
        h = mid - 1;
      else
        l = mid + 1;
    }
    if (i - l + 1 > ans) {
      ans = i - l + 1;
      ans2 = x[i];
    }
  }
  cout << ans << " " << ans2 << endl;
}
