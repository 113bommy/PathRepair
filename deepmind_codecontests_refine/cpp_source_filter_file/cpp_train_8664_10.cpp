#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200005], last, sum, ans[200005];
int main() {
  cin >> n >> m;
  for (long long i = (1); i <= (m); ++i) {
    cin >> a[i], sum += a[i];
    if (i + a[i] - 1 > n || (i == n && sum < n)) {
      cout << -1;
      exit(0);
    }
  }
  last = n + 1;
  for (long long i = (m); i >= (1); --i)
    ans[i] = max(i, last - a[i]), last = ans[i];
  for (long long i = (1); i <= (m); ++i) cout << ans[i] << " ";
  return 0;
}
