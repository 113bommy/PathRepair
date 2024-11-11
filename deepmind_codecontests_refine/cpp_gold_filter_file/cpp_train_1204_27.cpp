#include <bits/stdc++.h>
using namespace ::std;
const int maxn = 1e5 + 5;
int mark[maxn], prime[maxn], res;
void get_prime(int n) {
  memset(mark, 0, sizeof(mark));
  res = 0;
  for (int i = 2; i <= n; i++) {
    if (!mark[i]) mark[i] = prime[res++] = i;
    for (int j = 0; j < res && prime[j] * i <= n; j++) {
      mark[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) break;
    }
  }
}
int n, s, a[maxn];
void solve() {
  get_prime(100000);
  scanf("%d", &n);
  int maxx = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &s);
    for (int j = 0; prime[j] * prime[j] <= s && j < res; j++) {
      if (s % prime[j] == 0) {
        a[prime[j]]++;
        maxx = max(maxx, a[prime[j]]);
        while (s % prime[j] == 0) s /= prime[j];
      }
    }
    if (s > 1) {
      a[s]++;
      maxx = max(maxx, a[s]);
    }
  }
  printf("%d\n", maxx);
}
int main() {
  solve();
  return 0;
}
