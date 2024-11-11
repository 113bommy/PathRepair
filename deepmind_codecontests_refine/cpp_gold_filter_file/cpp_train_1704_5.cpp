#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int sz, q, arr[100005];
int main() {
  scanf("%d", &sz);
  for (int i = 1; i <= sz; i++) scanf("%d", &arr[i]);
  scanf("%d", &q);
  while (q--) {
    int t, l, r, x;
    scanf("%d %d %d", &t, &l, &r);
    if (t == 1) {
      long long tmp = 0;
      for (int i = l; i <= r; i++) {
        tmp += arr[i];
      }
      printf("%I64d\n", tmp);
    } else if (t == 2) {
      scanf("%d", &x);
      for (int i = l; i <= r; i++) {
        arr[i] ^= x;
      }
    }
  }
  return 0;
}
