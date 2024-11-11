#include <bits/stdc++.h>
using namespace std;
int n;
long long l[100010];
int main() {
  long long maxx = 0, sum = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d", &l[i]);
    maxx = max(maxx, l[i]);
    sum += l[i];
  }
  sum -= maxx;
  printf("%I64d", maxx - sum + 1);
  return 0;
}
