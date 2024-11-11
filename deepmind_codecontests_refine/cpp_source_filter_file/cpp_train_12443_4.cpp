#include <bits/stdc++.h>
using namespace std;
long long sum[3000005];
int main() {
  long long s, x;
  cin >> s >> x;
  long long l1 = log(s) / log(2) / 2 + 1;
  long long a = 0;
  for (long long i = 0; i < (1ll << l1); i++) {
    a = i ^ (x % (1ll << l1));
    sum[i + a]++;
  }
  long long l2 = log(s) / log(2) + 1 - l1;
  long long ans = 0;
  for (long long i = 0; i < (1ll << l2); i++) {
    a = i ^ (x % (1ll << l1));
    if (s >= (i + a) * (1ll << l1) && (s - (i + a) * (1ll << l1) < 3000000))
      ans += sum[s - (i + a) * (1ll << l1)];
  }
  if (0ll ^ s == x) ans -= 2;
  cout << ans;
  return 0;
}
