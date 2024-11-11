#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;
int main() {
  int n;
  scanf("%d", &n);
  long long nf = 1;
  long long ret = 0;
  for (int i = 2; i <= n; i++) {
    long long nnf = (nf * i) % mod;
    long long nret = i * (ret + nf - 1) % mod;
    ret = nret;
    nf = nnf;
  }
  ret += nf;
  ret %= mod;
  printf("%d\n", ret);
  return 0;
}
