#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long a[maxn];
int nno[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  long long k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  nno[n - 1] = n;
  for (int i = n - 2; i >= 0; --i) {
    if (a[i + 1] > 1)
      nno[i] = i + 1;
    else
      nno[i] = nno[i + 1];
  }
  int ans = 0;
  long long mex = (long long)(2e13 + 5) * k;
  for (int i = 0; i < n; ++i) {
    long long prod = 1, sum = 0;
    for (int j = i; j < n && prod < mex / a[j]; j = nno[j]) {
      prod *= a[j];
      sum += a[j];
      if (prod == sum * k) ans++;
      if (prod > sum * k && prod <= (sum + nno[j] - j - 1) * k && prod % k == 0)
        ans++;
      sum += nno[j] - j - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
