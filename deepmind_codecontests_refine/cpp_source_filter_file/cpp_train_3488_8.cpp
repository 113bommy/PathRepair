#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200050;
const int MAXE = 400050;
int main() {
  long long a, b, k;
  scanf("%I64d%I64d%I64d", &k, &a, &b);
  if (b <= 0) {
    b = -b;
    a = -a;
    swap(a, b);
  }
  long long ans = (b - a) / k;
  if (a < 0 || a % k == 0) ans++;
  printf("%I64d", ans);
  return 0;
}
