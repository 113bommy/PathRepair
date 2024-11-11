#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize(2)
#pragma G++ optimize(2)
using namespace std;
constexpr long long N = 1e5 + 9;
constexpr long long M = 2e5 + 9;
constexpr long long INF = 0x3f3f3f3f3f3f3f3f;
constexpr long long INF2 = 0xcfcfcfcfcfcfcfcf;
long long n, k;
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  long long a = (n - k) / 2;
  for (long long i = 1; i <= n; i++) cout << (i % (a + 1) > 0);
  cout << endl;
  return 0;
}
