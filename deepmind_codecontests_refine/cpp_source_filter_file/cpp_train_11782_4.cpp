#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
double eps = 1e-12;
void init_code() {}
long long brsrch(long long k, long long n, long long a, long long b) {
  long long l = 0, h = n;
  long long ans = 0;
  while (l <= h) {
    long long mid = l + (h - l) / 2;
    if (mid * a + (n - mid) * b < k && k - mid * a >= a) {
      ans = mid;
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long k, n, a, b;
    cin >> k >> n >> a >> b;
    if (k - n * b > 0) {
      cout << brsrch(k, n, a, b) << "\n";
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
