#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 2;
const int INF = (int)1e9 + 7;
const long long linf = (long long)1e14;
void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  if ((n * (n - 1)) / 2 < k) {
    printf("no solution\n");
    return;
  }
  int timer = 0;
  for (int i = 0; i < n; ++i) {
    printf("0 %d\n", timer);
    ++timer;
  }
}
int main() {
  int tt = 1;
  while (tt--) solve();
  return 0;
}
