#include <bits/stdc++.h>
const int maxn = 100005;
using namespace std;
int main() {
  long long c, a, t[maxn];
  int n;
  while (scanf("%d %lld", &n, &c) != EOF) {
    if (n == 1) {
      printf("%d\n", n);
      break;
    }
    for (int i = 0; i < n; i++) scanf("%lld", &t[i]);
    a = 1;
    for (int i = 1; i < n; i++) {
      if (t[i] - t[i - 1] > c) {
        a = 1;
      } else if (t[i] - t[i - 1] <= c) {
        a++;
      }
    }
    printf("%lld\n", a);
  }
  return 0;
}
