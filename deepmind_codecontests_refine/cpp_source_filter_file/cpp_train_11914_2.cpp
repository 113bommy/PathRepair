#include <bits/stdc++.h>
using namespace std;
bool one[101];
int main() {
  int n, a, i;
  scanf("%d %d %d", &n, &a, &i);
  while (a--) {
    scanf("%d", &i);
    one[i] = true;
  }
  for (i = i; i <= n; i++) {
    if (i > 1) printf(" ");
    printf("%d", one[i] ? 1 : 2);
  }
  return 0;
}
