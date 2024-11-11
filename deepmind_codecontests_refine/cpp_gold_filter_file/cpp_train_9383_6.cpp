#include <bits/stdc++.h>
using namespace std;
long long n, k, m, a[100005];
long long sum;
double ans;
int main() {
  ios_base::sync_with_stdio(false);
  cout << setprecision(10);
  cin >> n >> k >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  for (int i = 0; i <= min(m, n - 1); i++) {
    ans = max(ans, (double)(sum + min((n - i) * k, m - i)) / (n - i));
    sum -= a[i];
  }
  cout << ans << endl;
  ;
  return 0;
}
