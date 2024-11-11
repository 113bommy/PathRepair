#include <bits/stdc++.h>
using namespace std;
long long n, la, lb, tot;
int m, k, ans;
int main() {
  scanf("%lld%d%d", &n, &m, &k);
  lb = k - 1;
  while (m--) {
    long long tmp;
    scanf("%lld", &tmp);
    if (lb + (tmp - la) < k)
      lb += tmp - la;
    else {
      ans++;
      la += tot;
      tot = 0;
      lb += tmp - la;
      lb %= k;
    }
    tot++;
    la = tmp;
  }
  printf("%d\n", ans);
}
