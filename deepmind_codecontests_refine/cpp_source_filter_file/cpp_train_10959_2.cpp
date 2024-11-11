#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long M;
    scanf("%lld", &M);
    printf("%lld\n", (M / 4 + 1) % mod * ((M / 2 + 1) / 2 + 1) % mod);
  }
}
