#include <bits/stdc++.h>
using namespace std;
long long n, k, ar[1000005], tr[1000005], pr[1000005];
pair<long long, long long> br[1000005];
int main() {
  cin >> n >> k;
  if (k == 1) {
    cout << "3";
    return 0;
  }
  if (k == 2) {
    cout << "6";
    return 0;
  }
  for (int i = 2; i < n + 1; i++) {
    ar[i] = i;
    tr[i] = 1;
    pr[i] = 1;
  }
  for (int i = 2; i < n + 1; i++) {
    if (pr[i]) {
      for (int j = i; j < 1000005; j += i) {
        pr[j] = 0;
        tr[j] *= (i - 1);
        ar[j] /= i;
      }
    }
  }
  long long size_ = 0;
  for (int j = 3; j <= n; j++) {
    ar[j] *= tr[j];
    if (j == 4) {
      br[size_++] = (make_pair(3, 4));
      continue;
    }
    br[size_++] = (make_pair(ar[j], j));
  }
  sort(br, br + size_);
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    ans += br[i].first;
  }
  cout << ans + 1;
  return 0;
}
