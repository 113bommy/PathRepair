#include <bits/stdc++.h>
using namespace std;
long long int p, K;
long long int fastPow(long long int base, long long int pow) {
  long long int ans = 1;
  while (pow) {
    if (pow & 1) ans = (ans * base) % 1000000007;
    base = (base * base) % 1000000007;
    pow >>= 1;
  }
  return ans;
}
bool vis[1100000];
int main() {
  scanf("%I64d%I64d", &p, &K);
  if (K == 0) {
    printf("%I64d\n", fastPow(p, p - 1));
    return 0;
  } else if (K == 1) {
    printf("%I64d\n", fastPow(p, p));
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < p; i++) {
    if (vis[i]) continue;
    int size = 0;
    long long int tmp = i;
    while (!vis[tmp]) {
      size++;
      vis[tmp] = true;
      tmp = tmp * K % p;
    }
    if (size > 1) cnt++;
  }
  printf("%I64d\n", fastPow(p, cnt));
  return 0;
}
