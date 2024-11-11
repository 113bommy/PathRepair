#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 7;
int n;
int a[maxn], b[maxn];
long long solve() {
  long long res = 0;
  for (int i = 0; i < int(n); i++) {
    long long sa = 0, sb = 0;
    for (int j = i + 1; j < int(n); j++) {
      sa |= a[j];
      sb |= b[j];
      res = max(res, sa + sb);
    }
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < int(n); i++) scanf("%d", &a[i]);
  for (int i = 0; i < int(n); i++) scanf("%d", &b[i]);
  printf("%lld\n", solve());
  return 0;
}
