#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k;
unsigned long long a[2 * N];
int r[2 * N];
int p[2 * N];
unsigned long long _find(int x) { return (p[x] == x) ? x : p[x] = _find(p[x]); }
void print() {
  for (int i = 0; i < k; ++i) {
    printf("%d ", r[i]);
  }
  printf("\n");
}
int main() {
  int i, j;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; ++i) {
    scanf("%llu", &a[i]);
    p[i] = i;
  }
  unsigned long long limit = (unsigned long long)n / k;
  unsigned long long m = 0;
  for (i = 0; i < n; ++i) {
    int t = _find(a[i] % k);
    if (r[t] < limit) {
      m += (unsigned long long)(abs(k + t - (int)(a[i] % k)) % k);
      r[t]++;
      a[i] += (unsigned long long)(abs(k + t - (int)(a[i] % k)) % k);
    }
    if (r[t] == limit) p[t] = (t + 1) % k;
  }
  printf("%llu\n", m);
  for (i = 0; i < n; ++i) {
    printf("%llu ", a[i]);
  }
  printf("\n");
}
