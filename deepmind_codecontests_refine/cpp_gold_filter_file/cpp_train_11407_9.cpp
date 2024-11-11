#include <bits/stdc++.h>
using namespace std;
int a[100005], b[3000005];
int main() {
  int n, x;
  while ((scanf("%d%d", &n, &x)) != EOF) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      b[a[i]]++;
    }
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
      b[a[i]]--;
      if (b[x ^ a[i]]) {
        cnt += b[x ^ a[i]];
      }
    }
    printf("%I64d\n", cnt);
  }
  return 0;
}
