#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979323846;
const long long mod = 1e9 + 7;
const long long N = 5e5;
long long n, res, d[N];
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> n;
  d[1] = 1;
  for (long long i = 2; i <= 10; d[i] = d[i - 1] * 10, ++i)
    ;
  for (long long i = 1; i <= 10; ++i) {
    if (d[i] <= n && n <= d[i + 1] - 1) {
      res += (n - d[i] + 1) * i;
      break;
    }
    res += (d[i + 1] - d[i]) * i;
  }
  cout << res;
  return 0;
}
