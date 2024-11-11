#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e18;
const double eps = 1e-9;
const double pi = acos(-1.0);
long long n, ans;
pair<long long, long long> a;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a.first >> a.second;
    long long k = a.first + 1;
    while (1 << (2 * k - 2 * a.first) < a.second) k++;
    ans = max(ans, k);
  }
  cout << ans << endl;
}
