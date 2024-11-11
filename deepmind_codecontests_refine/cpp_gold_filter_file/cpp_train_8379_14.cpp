#include <bits/stdc++.h>
const int mod = 1000000007;
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  long long ans = 1;
  for (int i = 0; i < 3 * n; i++) {
    ans = (ans * 3) % mod;
  }
  long long ret = 1;
  for (int i = 0; i < n; i++) {
    ret = (ret * 7) % mod;
  }
  printf("%I64d\n", (ans - ret + mod) % mod);
  return 0;
}
