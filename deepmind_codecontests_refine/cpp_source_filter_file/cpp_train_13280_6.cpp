#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
int a[N], b[N];
long long n = 0, k = 0;
int main() {
  scanf("%I64d%I64d", &n, &k);
  int t = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &t);
    ++a[t];
  }
  long long cnt = 0;
  for (int i = 1e6; i >= 1; --i) {
    cnt += 1LL * a[i];
    if (cnt >= k) {
      printf("%d", i);
      return 0;
    }
    a[i / 2] += a[i] + b[i];
    b[i - i / 2] += a[i] + b[i];
  }
  printf("-1");
  return 0;
}
