#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long s[N], g[N], ans[N];
long long lmax[N], rmax[N];
int main() {
  long long n, cnt = 0;
  scanf("%I64d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d%I64d", s + i, g + i);
  lmax[1] = s[1] + g[1];
  for (int i = 1; i < n; i++) {
    lmax[i + 1] = min(s[i + 1] + g[i + 1], lmax[i] + 1);
  }
  rmax[n] = s[n] + g[n];
  for (int i = n - 1; i >= 1; i--) {
    rmax[i] = min(rmax[i + 1] + 1, s[i] + g[i]);
  }
  for (int i = 1; i <= n; i++) {
    ans[i] = min(lmax[i], rmax[i]);
    if (ans[i] > s[i])
      cnt += ans[i] - s[i];
    else {
      printf("-1\n");
      exit(0);
    }
  }
  cout << cnt << endl;
  for (int i = 1; i <= n; i++) {
    printf("%I64d ", ans[i]);
  }
  return 0;
}
