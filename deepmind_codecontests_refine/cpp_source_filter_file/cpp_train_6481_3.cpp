#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  scanf("%lld", &t);
  while (t--) {
    long long int n;
    scanf("%lld", &n);
    long long int a[n], one = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == 1)
        one++;
      else
        break;
    }
    if (one % 2 == 0)
      printf("FIRST\n");
    else
      printf("SECOND\n");
  }
  return 0;
}
