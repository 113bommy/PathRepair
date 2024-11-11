#include <bits/stdc++.h>
using namespace std;
bool b[9];
long long ans[12345];
long long n, m;
int main() {
  scanf("%I64d%I64d", &n, &m);
  m = 1;
  int k = 0;
  while (n > 0)
    for (int i = 45; i >= 0; --i) {
      if ((1LL << i) - 1 > n) continue;
      long long temp = 1LL << i;
      --temp;
      for (int j = 0; j < i; ++j) {
        ans[k++] = m;
      }
      m += 1234567899;
      n -= temp;
    }
  printf("%d\n%I64d", k, ans[0]);
  for (int i = 1; i < k; ++i) printf(" %I64d", ans[i]);
  printf("\n");
}
