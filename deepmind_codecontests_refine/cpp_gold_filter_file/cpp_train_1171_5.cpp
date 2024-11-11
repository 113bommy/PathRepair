#include <bits/stdc++.h>
using namespace std;
int H[100005];
int M[100005];
int A[100005];
int main() {
  int n, h, m, k;
  scanf("%d%d%d%d", &n, &h, &m, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &H[i], &M[i]);
    A[i] = M[i] % (m / 2);
  }
  sort(A, A + n);
  int ans = n + 1;
  int t = 0;
  for (int i = 0; i < n; i++) {
    int s = A[i] + 1;
    int e = A[i] + 1 + (k - 2);
    if (s == m / 2) {
      s -= m / 2;
      e -= m / 2;
    }
    int tempS = lower_bound(A, A + n, s) - A;
    int tempE = 0;
    int tempRes = 0;
    if (e >= m / 2) {
      e -= m / 2;
      tempE = lower_bound(A, A + n, e + 1) - A;
      tempRes = tempE + n - (tempS);
    } else {
      tempE = lower_bound(A, A + n, e + 1) - A;
      tempRes = tempE - tempS;
    }
    if (tempRes < ans) {
      ans = tempRes;
      t = (e + 1) % (m / 2);
    }
  }
  printf("%d %d\n", ans, t);
  for (int i = 0; i < n; i++) {
    int a = M[i] % (m / 2);
    int tempRes = (t - a + m / 2) % (m / 2);
    if (tempRes > 0 && tempRes < k) {
      printf("%d ", i + 1);
    }
  }
  return 0;
}
