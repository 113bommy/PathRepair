#include <bits/stdc++.h>
using namespace std;
const int N = 200500;
long long a[N];
long long pre[N];
int main(int argc, const char* argv[]) {
  int n;
  scanf("%d", &n);
  for (int x, i = 1; i <= n; ++i) {
    scanf("%d", &x);
    a[x]++;
  }
  for (int i = 1; i < N; ++i) {
    pre[i] = pre[i - 1] + a[i];
  }
  long long ans = 0;
  for (long long i = 1; i < N; ++i) {
    long long tmp = 0;
    if (a[i] == 0) continue;
    for (long long k = 1; (k + 1) * i - 1 < N; ++k) {
      tmp += (pre[(k + 1) * i - 1] - pre[k * i - 1]) * k * i;
    }
    ans = max(ans, tmp);
  }
  printf("%lld\n", ans);
  return 0;
}
