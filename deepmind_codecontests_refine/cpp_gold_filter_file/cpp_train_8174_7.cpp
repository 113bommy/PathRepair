#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010], sol[100010];
int c[100010], d[100010];
long long A[100010], m[100010], M[100010];
int n;
void solution(int *a, int *b, int kier) {
  long long sa = 0, sb = 0;
  for (int i = 1; i <= n; i++) {
    sa += a[i], sb += b[i];
    A[i] = sa - sb;
  }
  m[0] = 1000000000000000LL;
  M[n + 1] = 1000000000000000LL;
  for (int i = 1; i <= n; i++) {
    m[i] = min(A[i], m[i - 1]);
  }
  for (int i = n; i >= 1; i--) {
    M[i] = min(A[i], M[i + 1]);
  }
  long long mm = 0;
  long long MM = M[1];
  if (mm >= 0 && MM >= 0) {
    if (!kier)
      sol[1] = 1;
    else
      sol[n] = 1;
  }
  for (int i = 2; i <= n; i++) {
    MM = M[i] - A[i - 1];
    mm = m[i - 1] - (A[i - 1] - A[n]);
    if (mm >= 0 && MM >= 0) {
      if (!kier)
        sol[i] = 1;
      else
        sol[n - i + 1] = 1;
    }
  }
}
int main() {
  memset(sol, 0, sizeof(sol));
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i + 1);
    c[n - i] = a[i + 1];
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i + 1);
  }
  for (int i = 1; i <= n; i++) {
    d[i] = b[n - i];
  }
  d[n] = b[n];
  solution(a, b, 0);
  solution(c, d, 1);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (sol[i]) cnt++;
  }
  printf("%d\n", cnt);
  int k = 1;
  for (int i = 1; i <= n; i++) {
    if (sol[i]) {
      if (k < cnt) {
        printf("%d ", i);
        k++;
      } else {
        printf("%d\n", i);
      }
    }
  }
  return 0;
}
