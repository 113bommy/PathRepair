#include <bits/stdc++.h>
using namespace std;
int n, k;
long long d[1010000], a[1010000];
long long suma[1010000];
long long tmp1[1010000], tmp2[1010000];
void work() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    suma[i] = suma[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) scanf("%lld", &d[i]);
  long long ans = max(0ll, a[n] - d[n]);
  ;
  if (k == 0) {
    for (int i = 1; i <= n; i++) ans = max(ans, suma[n] - suma[i - 1] - d[i]);
  }
  if (k == 1) {
    long long mi2 = 0x3f3f3f3f3f3f3f3f;
    for (int i = n - 1; i >= 1; i--) {
      mi2 = min(mi2, a[i]);
      ans = max(ans, suma[n] - suma[i - 1] - mi2 - d[i]);
    }
    for (int i = n; i >= 1; i--) {
      tmp1[i] = max(tmp1[i + 1], suma[n] - suma[i - 1] - d[i]);
    }
    long long mi = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= n - 1; i++) {
      mi = min(mi, d[i]);
      ans = max(ans, tmp1[i + 1] + max(0ll, suma[i] - mi));
    }
  }
  if (k >= 2) {
    long long mi = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= n - 1; i++) mi = min(mi, d[i]);
    ans = max(ans, suma[n] - mi);
  }
  cout << ans << endl;
}
int main() {
  int casenum = 1;
  for (int testcase = 1; testcase <= casenum; testcase++) {
    work();
  }
  return ~~(0 ^ 0 ^ 0);
}
