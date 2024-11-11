#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  long long int tmp = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= 0) {
      tmp += a[i];
      printf("%lld ", tmp);
    } else {
      printf("%lld ", tmp + a[i]);
    }
  }
  printf("\n");
}
