#include <bits/stdc++.h>
using namespace std;
const int N = 1000050;
long long arr[N];
int main() {
  int k, b, n;
  long long res(0);
  scanf("%d%d%d", &k, &b, &n);
  if (b == 0) {
    int ccnt(0), a;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a);
      if (a)
        ccnt = 0;
      else
        ++ccnt;
      res += ccnt;
    }
    printf("%I64d\n", res);
  } else {
    map<int, int> C;
    C[0] = 1;
    int a, csum(0), zcnt(0);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a);
      arr[i] = a;
      if (a)
        zcnt = 0;
      else
        ++zcnt;
      csum = (csum + a) % (k - 1);
      res += C[(csum - (b % (k - 1)) + k - 1) % (k - 1)];
      C[csum]++;
      if (b % (k - 1) == 0) res -= zcnt;
    }
    printf("%I64d\n", res);
    if (n > 50000) {
      fprintf(stdout, "%d %d %d\n", k, b, n);
      for (int i = 1; i <= n; ++i) {
        fprintf(stdout, "%d ", arr[i]);
        if (i % 10 == 0) fprintf(stdout, "\n");
      }
    }
  }
  return 0;
}
