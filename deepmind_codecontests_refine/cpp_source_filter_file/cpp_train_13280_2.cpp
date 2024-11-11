#include <bits/stdc++.h>
using namespace std;
int a[2000000];
long long b[10000000], c[10000000];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  long long int coun = 0, lol = 0, mlol = 0;
  for (int i = 1; i <= n; i++) b[a[i]] += 1;
  for (int i = 10000000; i >= 1; i--) {
    lol += b[i];
    lol -= c[i];
    b[i - i / 2] += b[i];
    b[i / 2] += b[i];
    c[i - i / 2] += b[i];
    if (lol >= k) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("-1\n");
}
