#include <bits/stdc++.h>
using namespace std;
long long int a[200001], b[200001], n;
bool check(int sum) {
  long long int i, j, k = 0;
  for (i = 0; i < n; i++) {
    if (sum < a[i]) {
      k += b[i];
    }
  }
  return k <= sum;
}
int solve() {
  int l = 0, h = 2e9, ans;
  while (l <= h) {
    int mid = (l + h) / 2;
    if (check(mid)) {
      ans = mid;
      h = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int i, j, k;
    scanf("%lld", &n);
    for (i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
    }
    for (i = 0; i < n; i++) {
      scanf("%lld", &b[i]);
    }
    printf("%d", solve());
  }
}
