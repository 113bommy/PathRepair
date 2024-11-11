#include <bits/stdc++.h>
using namespace std;
const int MXN = (int)2e6 + 10;
const int INF = (int)1e9 + 7;
const long long LINF = (long long)1e18;
const double EPS = (double)1e-9;
int n;
long long k;
long long d[100];
int a[MXN];
int main() {
  cin >> n >> k;
  d[1] = d[0] = 1LL;
  for (int i = 2; i <= 50; ++i) d[i] = d[i - 1] + d[i - 2];
  for (int cur = n, cur1 = 1;;) {
    if (k <= d[cur - 1]) {
      a[cur1] = cur1;
      ++cur1;
      --cur;
    } else {
      k -= d[cur - 1];
      a[cur1] = cur1 + 1;
      a[cur1 + 1] = cur1;
      cur1 += 2;
      cur -= 2;
    }
    if (cur1 == n + 1) break;
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }
  return 0;
}
