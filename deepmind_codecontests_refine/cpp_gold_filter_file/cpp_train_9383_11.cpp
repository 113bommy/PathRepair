#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, k;
  cin >> n >> k >> m;
  vector<long long> X(n);
  vector<long long> count(n, k);
  long long total = 0;
  for (int i = 0; i < n; ++i) {
    cin >> X[i];
    total += X[i];
  }
  sort(X.begin(), X.end());
  vector<long long> prefixsums(n);
  prefixsums[0] = X[0];
  for (int i = 1; i < n; ++i) prefixsums[i] = prefixsums[i - 1] + X[i];
  long double ans = ((long double)(total + min(n * k, m))) / n;
  for (int i = 0; i < min(n - 1, m); ++i) {
    ans = max(ans, ((long double)(total - prefixsums[i] +
                                  min((n - i - 1) * k, m - (i + 1)))) /
                       (n - i - 1));
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
