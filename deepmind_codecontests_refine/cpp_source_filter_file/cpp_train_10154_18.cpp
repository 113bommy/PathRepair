#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int n;
long long int ort[100], p[100], a[MAXN], b[MAXN];
int main() {
  long long int cur = 0LL;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld", &a[i], &b[i]);
    cur ^= a[i];
    a[i] ^= b[i];
  }
  a[n] = cur;
  int len = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < len; j++) {
      if (a[i] & p[j]) a[i] ^= p[j];
    }
    if (a[i]) {
      ort[len++] = a[i];
      p[len - 1] = (a[i] ^ (a[i - 1]) + 1) >> 1;
    }
  }
  if (a[n])
    printf("1/1\n");
  else
    printf("%lld/%lld\n", (1LL << len) - 1, 1LL << len);
  return 0;
}
