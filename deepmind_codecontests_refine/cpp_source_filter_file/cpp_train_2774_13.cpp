#include <bits/stdc++.h>
using namespace std;
const int maxn = 100050;
const long long INF = 1e18 + 10;
long long a[maxn];
long long n, k;
int main() {
  cin >> n >> k;
  if (n == 0)
    cout << "0 0" << endl;
  else {
    long long left = INF, ans = 0;
    for (int i = 1; i <= k; i++) {
      cin >> a[i];
      if (n % a[i] < left) ans = i, left = n % a[i];
    }
    printf("%lld %lld\n", ans, n / a[ans]);
  }
  return 0;
}
