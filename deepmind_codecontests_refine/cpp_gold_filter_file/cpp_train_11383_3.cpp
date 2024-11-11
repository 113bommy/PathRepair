#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1000000];
long long w[1000000];
long long d[1000000];
int maxx(int i) {
  int sz = 1;
  while (i + sz * 2 < n) sz <<= 1;
  return i + sz;
}
int main(void) {
  scanf("%d ", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d ", &a[i]);
  }
  long long prev = 0;
  for (int i = 0; i < n - 1; i++) {
    printf("%I64d\n", a[i] + prev);
    prev += a[i];
    a[maxx(i)] += a[i];
  }
}
