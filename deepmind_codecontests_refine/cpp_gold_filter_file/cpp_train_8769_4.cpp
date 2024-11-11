#include <bits/stdc++.h>
const int MAX = 1000005;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-6;
const long double PI = acosl(-1.0);
using namespace std;
long long soma(long long a) { return a * (a + 1) / 2; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, x;
  cin >> n >> x;
  vector<long long> d(2 * n), sum(2 * n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    d[n + i] = d[i];
    sum[i] = sum[n + i] = soma(d[i]);
  }
  for (int i = 1; i < 2 * n; i++) {
    sum[i] += sum[i - 1];
    d[i] += d[i - 1];
  }
  long long ans = 0;
  for (int i = n; i < 2 * n; i++) {
    long long val = d[i] - x + 1;
    long long low = lower_bound(d.begin(), d.end(), val) - d.begin();
    long long valsum = sum[i] - sum[low];
    long long rest = x - (d[i] - d[low]);
    long long restsum =
        soma(d[low] - d[low - 1]) - soma(d[low] - d[low - 1] - rest);
    ans = max(ans, valsum + restsum);
  }
  cout << ans << '\n';
  return 0;
}
