#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> a(2 * n);
  int lool_dos = 0;
  for (long long i = 0; i < 2 * n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  long long min_x = a[0];
  long long max_x = a[n - 1];
  long long min_y = a[n];
  long long max_y = a[2 * n - 1];
  long long ans = (max_x - min_x) * (max_y - min_y);
  for (long long i = n; i <= 2 * (n - 1); i++) {
    ans = min(ans, (a[2 * n - 1] - a[0]) * (a[i] - a[i - n + 1]));
  }
  cout << ans << "\n";
}
