#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], ans = 0;
  for (int i = (0); i < (n); ++i) cin >> a[i];
  for (int l = (0); l < (n); ++l) {
    long long k = 2LL << (int)log2(a[l]), sum = 0;
    for (int r = (l + 2); r < (n); ++r) {
      sum += a[r - 1];
      if (sum >= k) break;
      if ((a[l] >= a[r]) and (a[l] ^ a[r]) == sum) ++ans;
    }
  }
  for (int r = (n)-1; r >= (0); --r) {
    long long k = 2LL << (int)log2(a[r]), sum = 0;
    for (int l = (r - 1) - 1; l >= (0); --l) {
      sum += a[l + 1];
      if (sum >= k) break;
      if ((a[l] < a[r]) and (a[r] ^ a[l]) == sum) ++ans;
    }
  }
  cout << ans;
  return 0;
}
