#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int rd() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - 48, ch = getchar();
  return x;
}
int GetInv(int x) {
  int res = 1, k = mod - 2;
  while (k) {
    if (k & 1) res = (long long)res * x % mod;
    x = (long long)x * x % mod;
    k >>= 1;
  }
  return res;
}
int main() {
  int n = rd(), ans = 0;
  for (int i = 1; i <= n; i++)
    ans = (long long)(ans + 1) * 100 * GetInv(rd()) % mod;
  printf("%d", ans);
  return 0;
}
