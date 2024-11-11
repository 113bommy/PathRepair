#include <bits/stdc++.h>
using namespace std;
long long a[210000], id[210000], n, k;
long long sum[210000], m[210000];
int main() {
  cin >> n >> k;
  int i;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = n - k + 1; i <= n; i++) sum[n - k + 1] += a[i];
  id[n - k + 1] = n - k + 1;
  m[n - k + 1] = sum[n - k + 1];
  for (i = n - k; i >= 1; i--) {
    sum[i] = sum[i + 1] - a[i + k] + a[i];
    if (sum[i] >= m[i + 1]) {
      m[i] = sum[i];
      id[i] = i;
    } else {
      m[i] = m[i + 1];
      id[i] = id[i + 1];
    }
  }
  long long ans = 0, pre, last;
  for (i = 1; i + k + k - 1 <= n; i++) {
    if (sum[i] + m[i + k] > ans) {
      ans = sum[i] + m[i + k];
      pre = i;
      last = id[i + k];
    }
  }
  cout << pre << " " << last << endl;
}
