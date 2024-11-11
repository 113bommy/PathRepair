#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
long long ans[N];
int main() {
  int n;
  long long w;
  scanf("%d%lld", &n, &w);
  long long res = 0;
  long long mi = 0;
  long long mx = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &ans[i]);
    res += ans[i];
    mx = max(res, mx);
    mi = min(res, mi);
  }
  if (abs(mi) + mx > w)
    printf("0\n");
  else {
    printf("%lld\n", (w - mx) - abs(mi) + 1);
  }
  return 0;
}
