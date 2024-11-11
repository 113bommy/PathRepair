#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000], b[1000];
int main() {
  scanf("%d", &n);
  if (n > 36) {
    printf("-1");
    return 0;
  }
  while (n > 1) {
    printf("8");
    n -= 2;
  }
  if (n) printf("6");
  return 0;
}
