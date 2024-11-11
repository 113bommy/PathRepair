#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long a[n];
    int cntodda = 0, cntevena = 0, cntoddb = 0, cntevenb = 0;
    for (int i = 0; i < n; i++) {
      scanf("%ld", &a[i]);
      if (a[i] % 2 == 0)
        cntevena++;
      else
        cntodda++;
    }
    int m;
    scanf("%d", &m);
    long b[m];
    for (int i = 0; i < m; i++) {
      scanf("%ld", &b[i]);
      if (b[i] % 2 == 0)
        cntevenb++;
      else
        cntoddb++;
    }
    long long cnt = cntodda * cntoddb + cntevena * cntevenb;
    printf("%lld\n", cnt);
  }
}
