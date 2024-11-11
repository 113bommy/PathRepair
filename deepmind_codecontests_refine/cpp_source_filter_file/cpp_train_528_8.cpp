#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
long long n, m, k;
void Main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  if (n > m) swap(n, m);
  if (k < m)
    return puts("-1"), void();
  else {
    int flag1 = (k - n) % 2, flag2 = (m - n) % 2;
    if (flag1 == 0 && flag2 == 0) printf("%lld\n", k);
    if (flag1 == 0 && flag2 == 1) printf("%lld\n", k - 1);
    if (flag1 == 1 && flag2 == 0) printf("%lld\n", k - 2);
    if (flag1 == 1 && flag2 == 1) printf("%lld\n", k);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) Main();
  return 0;
}
