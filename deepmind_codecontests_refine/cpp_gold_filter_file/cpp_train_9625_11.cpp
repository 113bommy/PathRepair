#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  printf("YES\n");
  int s = 0;
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", i, s);
    s += i;
  }
  return 0;
}
