#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int A[200007];
long long int maxST[200007][20];
long long int orST[200007][20];
void precalc(long long int n) {
  long long int i, j;
  for (i = 0; i < n; i++) orST[i][0] = maxST[i][0] = A[i];
  for (j = 1; (1 << j) <= n; j++) {
    for (i = 0; i < n; i++) {
      if ((i + (1 << j) - 1) < n) {
        orST[i][j] = (orST[i][j - 1]) | (orST[i + (1 << (j - 1))][j - 1]);
        maxST[i][j] = max(maxST[i][j - 1], maxST[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
}
long long int maxRange(long long int l, long long int r) {
  if (l > r) swap(l, r);
  long long int n = r - l + 1;
  long long int i = 0, msb = 0;
  while (i < 20) {
    if ((1 << i) & n) msb = i;
    i++;
  }
  return max(maxST[l][msb], maxST[r - (1 << msb) + 1][msb]);
}
long long int orRange(long long int l, long long int r) {
  if (l > r) swap(l, r);
  long long int n = r - l + 1;
  long long int i = 0, msb = 0;
  while (i < 20) {
    if ((1 << i) & n) msb = i;
    i++;
  }
  return (orST[l][msb] | orST[r - (1 << msb) + 1][msb]);
}
int main() {
  long long int i, j, k, l, m, n, p, q, x, y, z, a, b, r, ls, fs, md, ans;
  scanf("%lld", &n);
  for (i = 0; i < n; i++) scanf("%lld", &A[i]);
  precalc(n);
  ans = 0;
  for (i = 0; i < n; i++) {
    fs = i;
    ls = n - 1;
    while (fs + 1 < ls) {
      md = (fs + ls) / 2;
      if (orRange(i, md) <= A[i])
        fs = md;
      else
        ls = md;
    }
    if (orRange(i, ls) <= A[i])
      r = ls - i + 1;
    else
      r = fs - i + 1;
    fs = 0;
    ls = i;
    while (fs + 1 < ls) {
      md = (fs + ls) / 2;
      if ((orRange(md, i) <= A[i]) && (md == i || maxRange(md, i - 1) < A[i]))
        ls = md;
      else
        fs = md;
    }
    if ((orRange(fs, i) <= A[i]) && (fs == i || maxRange(fs, i - 1) < A[i]))
      l = i - fs + 1;
    else
      l = i - ls + 1;
    ans += l * r;
  }
  printf("%lld\n", n * (n + 1) / 2 - ans);
  return 0;
}
