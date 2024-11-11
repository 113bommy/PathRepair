#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e9 + 9;
const long long int MOD = 1e9 + 696969;
const long long INF = 1e18 + 3;
const int maxn = 1000 * 50;
vector<long long> tmp = {1, 5, 10, 50};
bitset<maxn + 5> da[2];
bitset<maxn + 5> poda[2];
int32_t main() {
  da[0].set(0, 1);
  long long n, mn;
  cin >> n;
  mn = min(n, 1000LL);
  for (long long i = (1); i <= (mn); ++i) {
    da[i & 1].reset();
    da[i & 1] = (da[(i & 1) ^ 1] << 1) | (da[(i & 1) ^ 1] << 5) |
                (da[(i & 1) ^ 1] << 10) | (da[(i & 1) ^ 1] << 50);
  }
  if (n == mn) {
    long long ret = 0;
    for (long long i = (1); i <= (50 * n); ++i) ret += da[n & 1][i];
    {
      cout << ret;
      exit(0);
    };
  }
  long long ret = 0;
  for (long long i = (1); i <= (50 * n); ++i) ret += da[mn & 1][i];
  cout << 49LL * (n - mn) + ret;
}
