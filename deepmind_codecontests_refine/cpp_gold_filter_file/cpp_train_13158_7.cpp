#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> v(n), sum(n - k + 1, 0);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < k; i++) sum[0] = sum[0] + v[i];
  for (int i = 1; i <= n - k; i++)
    sum[i] = sum[i - 1] + v[i + k - 1] - v[i - 1];
  long long maxi = sum[0];
  long long maxsum = sum[0] + sum[k];
  int a = 0, b = k, index = 0;
  for (int i = k; i <= n - k; i++) {
    if (sum[i - k] > maxi) {
      maxi = sum[i - k];
      index = i - k;
    }
    if (maxsum < sum[i] + maxi) {
      maxsum = sum[i] + maxi;
      b = i;
      if (b - index >= k) a = index;
    }
  }
  cout << a + 1 << ' ' << b + 1;
}
