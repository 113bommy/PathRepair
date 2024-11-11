#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 1000105;
const double PI = 4 * atan(1);
const double eps = 1e-7;
const long long oo = 1e10;
const int MAXN = 100500;
const int K = 21;
long long n, m;
long long a[N];
long long pos[N];
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  long long sum = 0;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum < n) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < m; i++) {
    long long res = n - i;
    long long ans = res - a[i] + 1;
    sum -= a[i];
    if (ans < 0) {
      cout << -1;
      return 0;
    }
    ans = (ans < sum + 1 ? ans : sum + 1);
    pos[i] = ans;
  }
  for (int i = 0; i < m; i++) {
    cout << pos[i] << " ";
  }
  return 0;
}
