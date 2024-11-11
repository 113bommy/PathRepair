#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  double n, k;
  cin >> n >> k;
  long long a[(long long)floor(n)];
  double sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (ceil(sum / n) == k) {
    cout << 0;
    return 0;
  }
  long long ans = ceil(2 * ((n * (k - 0.5)) - sum));
  cout << ans;
  return 0;
}
