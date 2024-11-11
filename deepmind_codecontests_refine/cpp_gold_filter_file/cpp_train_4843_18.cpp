#include <bits/stdc++.h>
using namespace std;
int n, A, cf, cm, a[100005], aa[100005];
pair<int, int> c[100005];
long long m;
long long f(int x) {
  long long allowance = 0;
  memcpy(aa, a, sizeof(int) * n);
  for (int i = 0; i < n; ++i) {
    if (a[i] < x) {
      allowance += x - a[i];
      aa[i] = x;
      if (allowance > m) return 0;
    } else
      break;
  }
  int mn = A;
  int mx = 0;
  for (int i = n - 1; i >= 0; --i) {
    int increase = A - max(a[i], x);
    if (allowance + increase <= m) {
      aa[i] = A;
      mx++;
      allowance += increase;
    } else {
      mn = min(mn, max(a[i], x));
    }
  }
  return 1LL * mn * cm + 1LL * mx * cf;
}
int main() {
  scanf("%d%d%d%d%I64d", &n, &A, &cf, &cm, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    c[i] = make_pair(a[i], i);
  }
  sort(a, a + n);
  sort(c, c + n);
  int L = a[0];
  int R = A;
  while (L < R) {
    int M = (L + R) / 2;
    if (f(M + 1) == 0)
      R = M;
    else
      L = M + 1;
  }
  R = L;
  L = a[0];
  while (L + 100 < R) {
    int M1 = (2LL * L + R) / 3;
    int M2 = (L + 2LL * R) / 3;
    if (f(M1) >= f(M2))
      R = M2;
    else
      L = M1;
  }
  int mxL = L++;
  while (L <= R) {
    if (f(mxL) < f(L)) mxL = L;
    ++L;
  }
  printf("%I64d\n", f(mxL));
  for (int i = 0; i < n; ++i) {
    a[c[i].second] = aa[i];
  }
  for (int i = 0; i < n; ++i) {
    if (i) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
}
