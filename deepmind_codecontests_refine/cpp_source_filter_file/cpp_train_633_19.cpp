#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 150;
const long long PHI = (long long)998244352;
const long long INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = (long long)1e9 + 7;
const long long OVER_FLOW = 0x7fffffff;
const long long LOVER_FLOW = 0x7fffffffffffffff;
int n;
long long C[MAXN][MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  long long res = 0;
  for (long long i = 2; i <= n; i++) {
    long long cur = n / i;
    if (cur <= 1) break;
    res += (cur * (cur + 1) / 2) - 1;
  }
  cout << res << endl;
  return 0;
}
