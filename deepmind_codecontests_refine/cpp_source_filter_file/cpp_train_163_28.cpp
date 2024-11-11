#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 1;
int n, A[N], B[N], k, f;
long long sol;
int main() {
  scanf("%d %d %d", &n, &k, &f);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d", &B[i]);
  }
  sort(A + 1, A + n + 1);
  sort(B + 1, B + n + 1);
  long long sol = 1e18;
  for (int i = 1; i <= k - n + 1; i++) {
    long long t = 0;
    for (int j = i; j <= i + n - 1; j++) {
      int x = abs(B[j] - A[j - i + 1]);
      int cur = B[j];
      int a = abs(f - cur);
      t += ((long long)x + (long long)a);
    }
    sol = min(t, sol);
  }
  printf("%I64d", sol);
  return 0;
}
