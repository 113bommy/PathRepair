#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const int maxn = 1e+5;
int n, m, k;
int main(int argc, const char* argv[]) {
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &k);
  long long ans = 1;
  if (k > n || k < 1) {
    for (int i = 0; i < n; i++) {
      ans = (ans * m) % MOD;
    }
  } else if (k == n) {
    for (int i = 0; i < (n + 1) / 2; ++i) {
      ans = (ans * m) % MOD;
    }
  } else if (k % 2 == 1) {
    ans = m * m;
  } else
    ans = m;
  cout << ans;
  return 0;
}
