#include <bits/stdc++.h>
using namespace std;
long long nums[100006];
long long sums[100006] = {0};
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) scanf("%I64d", &nums[i]);
  for (int i = 1; i <= n; ++i) sums[i] = sums[i - 1] + nums[i];
  if (sums[n] % 3 != 0 && sums[n] != 0) {
    cout << 0 << endl;
    return 0;
  }
  long long cur = 0, tot = 0;
  for (int i = 1; i < n; ++i) {
    if (sums[i] == 2 * (sums[n] / 3) && i > 1) tot += cur;
    if (sums[i] == sums[n] / 3) ++cur;
  }
  cout << tot << endl;
}
