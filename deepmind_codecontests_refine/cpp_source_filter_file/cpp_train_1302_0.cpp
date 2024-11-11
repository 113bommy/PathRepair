#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
bool vis[1000100];
long long p, k;
long long mod = 1000000007;
void go(long long s, int &cnt) {
  if (vis[s]) return;
  cnt++;
  vis[s] = true;
  go((s * k) % p, cnt);
}
int main() {
  scanf("%d %d", &p, &k);
  long long res = 1;
  if (k == 0) {
    for (int i = 0; i < p; i++) res *= p, res %= mod;
    printf("%lld\n", res);
    return 0;
  }
  for (int i = 1; i < p; i++) {
    if (!vis[i]) {
      int cnt = 0;
      go(i, cnt);
      res *= p;
      res %= mod;
    }
  }
  printf("%lld\n", res);
  return 0;
}
