#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long siz[N], a, b, sum;
long long n;
bool cmp(long long x, long long y) { return x > y; }
int main() {
  scanf("%I64d%I64d%I64d", &n, &a, &b);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &siz[i]);
    sum += siz[i];
  }
  sort(siz + 2, siz + n + 1, cmp);
  if (a * siz[1] >= b * sum) {
    puts("0");
    return 0;
  }
  for (int i = 2; i <= n; i++) {
    sum -= siz[i];
    if (a * siz[1] >= b * sum) {
      printf("%I64d\n", i - 1);
      break;
    }
  }
  return 0;
}
