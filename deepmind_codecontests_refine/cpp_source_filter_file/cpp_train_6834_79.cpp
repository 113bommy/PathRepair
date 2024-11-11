#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n > 36)
    printf("-1\n");
  else {
    int k = n % 2;
    if (k) printf("1");
    for (int i = 0; i < n / 2; i++) printf("8");
    printf("\n");
  }
  return 0;
}
