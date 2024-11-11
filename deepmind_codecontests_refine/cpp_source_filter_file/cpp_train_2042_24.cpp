#include <bits/stdc++.h>
using namespace std;
long long n, x, y, nr[1000002], ans = 1e18, a;
long long sum[1000002];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> x >> y;
  int miscari = (x + y - 1) / y;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    nr[a]++;
    sum[a] += a;
  }
  for (int i = 1; i <= 1e6; i++) {
    nr[i] += nr[i - 1];
    sum[i] += sum[i - 1];
  }
  for (int i = 2; i <= 1e6; i++) {
    long long second = 0;
    for (int j = i; j <= 1e6; j += i) {
      int last = max(j - i, j - miscari);
      second += (nr[last] - nr[j - i]) * x +
                ((nr[j] - nr[last]) * j - sum[j] + sum[last]) * y;
    }
    ans = min(ans, second);
  }
  cout << ans;
  return 0;
}
