#include <bits/stdc++.h>
const int mn = 1e5 + 10;
using namespace std;
int n, L, w, A[mn], B[mn], cnt1, cnt2;
long long ans;
int main() {
  int x, y;
  scanf("%d%d%d", &n, &L, &w);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    if (y == 1)
      A[++cnt1] = x;
    else
      B[++cnt2] = x;
  }
  sort(A + 1, A + cnt1 + 1);
  sort(B + 1, B + cnt2 + 1);
  int head = 1;
  for (int i = 1; i <= cnt1; i++) {
    while (head <= cnt1 &&
           abs(A[i] + B[head] + L) >= 1ll * (B[head] - A[i] + L))
      head++;
    ans += cnt2 - head + 1;
  }
  printf("%I64d\n", ans);
  return 0;
}
