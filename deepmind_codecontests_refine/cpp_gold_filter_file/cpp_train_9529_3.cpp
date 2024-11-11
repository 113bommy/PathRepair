#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const long long INF = 2e17;
int n, k, a[N];
long long pre[N], suf[N];
int main() {
  while (scanf("%d%d", &n, &k) == 2) {
    for (int i = 0; i <= n; i++) scanf("%d", &a[i]);
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + a[i - 1];
      if (pre[i] & 1) {
        for (int j = i; j <= n; j++) pre[j] = INF;
        break;
      }
      pre[i] /= 2;
    }
    suf[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
      suf[i] = suf[i + 1] + a[i + 1];
      suf[i] <<= 1;
      if (abs(suf[i]) > INF) {
        for (int j = i; j >= 0; j--) suf[j] = INF;
        break;
      }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
      if (pre[i] != INF && suf[i] != INF) {
        long long tmp = pre[i] + suf[i];
        if (abs(tmp) > k || (tmp == 0 && i == n)) continue;
        ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
