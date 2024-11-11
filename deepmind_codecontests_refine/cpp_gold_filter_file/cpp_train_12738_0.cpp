#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if (n & 1) {
    printf("-1\n");
  } else {
    for (int i = n; i > 0; i--) {
      if (i != n) {
        printf(" ");
      }
      printf("%d", i);
    }
  }
  return 0;
}
