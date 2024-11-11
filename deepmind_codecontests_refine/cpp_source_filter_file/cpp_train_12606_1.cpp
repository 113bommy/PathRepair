#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int LOGN = 20;
const int PI = acos(-1);
long long n, m, sum = 0;
long long a[N], b[N], d[N];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld", a + i, b + i);
    d[i] = a[i] - b[i];
    sum += a[i];
  }
  sort(d, d + n);
  int ans = 0;
  for (int i = n - 1; i > 0; i--) {
    if (sum <= m) break;
    sum -= d[i];
    ans++;
  }
  if (sum > m) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
