#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return (b != 0 ? gcd(b, a % b) : a); }
int lcm(int a, int b) { return (a / gcd(a, b) * b); }
int a[100005], b[100005];
int binarysearch(int x, int n);
int main(int argc, const char **argv) {
  int na, nb, k, m, i, lk;
  scanf("%d %d%d%d", &na, &nb, &k, &m);
  for (i = 0; i < na; i++) scanf("%d", &a[i]);
  for (i = 0; i < nb; i++) scanf("%d", &b[i]);
  lk = binarysearch(a[k - 1], nb);
  if (lk == -1) {
    if (b[0] > a[k - 1])
      lk = nb;
    else if (a[k - 1] > b[nb - 1])
      lk = 0;
  } else {
    i = lk;
    while (b[i] == a[k - 1]) i++;
    lk = nb - i;
  }
  if (m <= lk)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
int binarysearch(int x, int n) {
  int li = 0, ui = n - 1, mid;
  while (li <= ui) {
    mid = (li + ui) / 2;
    if (x == b[mid]) {
      return mid;
    } else if (x < b[mid]) {
      ui = mid - 1;
    } else
      li = mid + 1;
  }
  return -1;
}
