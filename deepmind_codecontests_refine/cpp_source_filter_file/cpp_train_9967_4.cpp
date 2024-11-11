#include <bits/stdc++.h>
using namespace std;
long long a[12] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};
int n;
int main() {
  scanf("%d", &n);
  if (n < 12)
    printf("%lld\n", a[n]);
  else {
    long long t = a[11];
    t = t + (n - 11ll) * 49;
    printf("%d\n", a[n] + t);
  }
  return 0;
}
