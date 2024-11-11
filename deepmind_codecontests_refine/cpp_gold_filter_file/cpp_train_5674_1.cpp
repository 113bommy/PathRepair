#include <bits/stdc++.h>
using namespace std;
int solve();
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
const int N = 2e2 + 5;
long long a[N][N];
long long cnt[N];
int solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%lld", &a[i][j]);
    }
  }
  for (int i = 1; i <= m; i++) {
    long long mx = -1, id = 0;
    for (int j = 1; j <= n; j++) {
      if (a[i][j] > mx) {
        mx = a[i][j];
        id = j;
      }
    }
    cnt[id]++;
  }
  long long ans = 0, id = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] > ans) {
      ans = cnt[i];
      id = i;
    }
  }
  printf(
      "%lld"
      "\n",
      id);
  return 0;
}
