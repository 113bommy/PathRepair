#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long x, k;
  scanf("%i", &n);
  for (int zzz = 0; zzz < n; zzz++) {
    scanf("%lli %lli", &k, &x);
    long long ans = 9 * k + x;
    printf("%lli", ans);
  }
}
