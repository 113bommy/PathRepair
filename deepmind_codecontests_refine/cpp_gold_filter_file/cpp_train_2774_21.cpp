#include <bits/stdc++.h>
using namespace std;
long long n, k, now, ans1, ans2;
long long a;
int main() {
  cin >> n >> k;
  now = 1e18;
  for (int i = 1; i <= k; i++) {
    scanf("%lld", &a);
    if (n % a < now) {
      now = n % a;
      ans1 = i;
      ans2 = n / a;
    }
  }
  cout << ans1 << " " << ans2;
  return 0;
}
