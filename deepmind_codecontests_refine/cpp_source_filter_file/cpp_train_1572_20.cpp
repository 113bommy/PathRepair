#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e9;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    cin >> a[i];
  }
  sort((a).begin(), (a).end());
  long long ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
  long long curmin = INF;
  for (int i = 1; i < n - 1; ++i) {
    curmin = min(curmin, a[i + n - 1] - a[i]);
  }
  ans = min(curmin * (a[2 * n - 1] - a[0]), ans);
  cout << ans << endl;
  return 0;
}
