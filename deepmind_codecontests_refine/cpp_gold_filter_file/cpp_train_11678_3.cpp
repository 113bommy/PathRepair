#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000;
const long long LINF = 1LL * INF * INF;
const long double PI = acos(-1.);
const double EPS = 1e-6;
long long mod = INF + 7;
const int maxn = 300010;
long long max1[20][maxn];
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  long long sum = 0;
  for (int i = 0; i < 20; ++i) max1[i][0] = LINF;
  max1[0][0] = 0;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    sum += arr[i];
    for (int z = 0; z < m; ++z) max1[z][i + 1] = max1[z][i];
    max1[(i + 1) % m][i + 1] =
        min(max1[(i + 1) % m][i + 1], sum - k * ((i + 1) / m));
    for (int z = 0; z < m; ++z) {
      ans = max(ans, sum - max1[z][(i + 1)] -
                         k * ((long long)(i + 1 - z + m - 1) / m));
    }
  }
  cout << ans;
  return 0;
}
