#include <bits/stdc++.h>
using namespace std;
const int maxint = -1u >> 1;
const int N = (int)2e5 + 10;
int n;
long long a[N], ans[N];
void UPD(int l, int r) {
  ans[l]++;
  ans[r + 1]--;
}
void calc(int x) {
  for (int i = 1, j; i < n; i = j + 1) {
    int k = (x - 2) / i;
    if (k) {
      j = (x - 2) / k;
      if (a[x] < a[k + 1]) UPD(i, j);
    } else {
      if (a[x] < a[1]) UPD(i, n - 1);
      break;
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (int i = 2; i <= n; i++) {
    calc(i);
  }
  for (int i = 1; i < n; i++) {
    ans[i] += ans[i - 1];
    printf("%I64d%c", ans[i], (i == n - 1) ? 10 : ' ');
  }
  return 0;
}
