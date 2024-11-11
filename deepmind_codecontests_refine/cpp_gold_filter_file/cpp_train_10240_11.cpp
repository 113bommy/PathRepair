#include <bits/stdc++.h>
using namespace std;
ifstream in("test.in");
ofstream out("test.out");
const int DIM = 100005;
long long arr[DIM], cst[DIM], psm[DIM];
long long solve(int n, int x) {
  if (cst[x] != -1) return cst[x];
  cst[x] = 0;
  for (long long i = n - 1, k = 1, l = x; i >= 1; i -= l, l *= x, ++k)
    cst[x] += (psm[i] - psm[max(0LL, i - l)]) * k;
  return cst[x];
}
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%I64d", &arr[i]);
  sort(arr + 1, arr + n + 1);
  fill(cst + 1, cst + DIM, -1);
  for (int i = 1; i <= n; ++i) psm[i] = arr[i] + psm[i - 1];
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    int x;
    scanf("%d", &x);
    printf("%I64d ", solve(n, x));
  }
  return 0;
}
