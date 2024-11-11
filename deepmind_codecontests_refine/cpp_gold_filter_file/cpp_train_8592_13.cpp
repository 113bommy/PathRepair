#include <bits/stdc++.h>
using namespace std;
int GLL(long long& x) { return scanf("%lld", &x); }
int GI(int& x) { return scanf("%d", &x); }
int t, n, r;
int main() {
  GI(t);
  while (t--) {
    GI(n);
    GI(r);
    int sum = 0;
    int f;
    for (int i = 0; i < (int)(n - 1); i++) {
      GI(f);
      sum += f;
    }
    int res = (((r - sum) % n) + n) % n;
    if (res == 0) res = n;
    printf("%d\n", res);
  }
  return 0;
}
