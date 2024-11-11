#include <bits/stdc++.h>
using namespace std;
const long long INFLL = (long long)2e18;
const long INF = (long)2e9, N = (long)1e5 + 1;
long d[N];
void solve() {
  long n;
  scanf("%ld", &n);
  fill(d, d + N, -1);
  for (long i = 0; i < n; ++i) {
    long x, k;
    scanf("%ld %ld", &x, &k);
    if (x - d[k] <= 1) {
      d[k] = max(d[k], x);
    } else {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
}
void init() { freopen("input.txt", "r", stdin); }
int main() {
  solve();
  return 0;
}
