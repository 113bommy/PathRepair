#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")
using namespace std;
long long ans = 1;
long long n, k;
long long a[200];
bool check(int x) {
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += ((a[i] - 1) / x + 1) * x - a[i];
  }
  return sum <= k;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  long long sum = k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  for (long long i = 1; i * i <= sum; ++i) {
    if (i > ans) {
      if (check(i)) {
        ans = i;
      }
    }
    if (sum / i > ans) {
      if (check(sum / i)) {
        ans = sum / i;
      }
    }
  }
  cout << ans;
  return 0;
}
