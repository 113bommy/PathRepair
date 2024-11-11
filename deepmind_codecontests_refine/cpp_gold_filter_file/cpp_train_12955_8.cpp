#include <bits/stdc++.h>
using namespace std;
const int MAX_K = 16;
long long os[MAX_K + 1];
int rec(long long n, int k) {
  if (n == 0) return 0;
  if (k == 1) return (int)n;
  int r = n / os[k];
  long long d0 = n - os[k] * r;
  long long d1 = os[k] * (r + 1) - n;
  return min(k * r + rec(d0, k - 1), k * (r + 1) + rec(d1, k - 1));
}
int main() {
  os[0] = 0;
  for (int k = 0; k < MAX_K; k++) os[k + 1] = os[k] * 10 + 1;
  long long n;
  scanf("%lld", &n);
  printf("%d\n", rec(n, MAX_K));
  return 0;
}
