#include <bits/stdc++.h>
using namespace std;
long long ar[100005];
long long s, n;
long long br[100005];
long long res(long k) {
  long long ans = 0;
  long i;
  for (i = 0; i < n; i++) {
    br[i] = ar[i] + (i + 1) * (long long)k;
  }
  sort(br, br + n);
  for (i = 0; i < k; i++) ans += br[i];
  return ans;
}
int main() {
  long i, low, mid, high;
  cin >> n >> s;
  for (i = 0; i < n; i++) cin >> ar[i];
  low = 0;
  high = n + 1;
  while (low < high - 1) {
    mid = (low + high) / 2;
    if (res(mid) <= s)
      low = mid;
    else
      high = mid;
  }
  cout << low << " " << res(low);
  return 0;
}
