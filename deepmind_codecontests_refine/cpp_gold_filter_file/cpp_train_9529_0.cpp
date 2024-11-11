#include <bits/stdc++.h>
using namespace std;
int A[210000], B[210000];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= n; i++) {
    scanf("%d", &A[i]);
    B[i] = A[i];
  }
  for (int i = 0; i < n; i++) {
    A[i + 1] += A[i] / 2;
    A[i] %= 2;
  }
  int minn = 0;
  for (int i = 0; i <= n; i++) {
    if (A[i]) {
      minn = i;
      break;
    }
  }
  int ans = 0;
  long long sum = 0;
  for (int i = n; i >= 0; i--) {
    sum = sum * 2 + A[i];
    if (sum >= 1e10 || sum <= -1e10) break;
    if (i <= minn) {
      long long tem = abs(sum - B[i]);
      if (tem == 0 && i == n) continue;
      if (tem <= k) ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
