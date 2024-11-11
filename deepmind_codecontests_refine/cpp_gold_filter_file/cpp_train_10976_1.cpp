#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, al = 0, x;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    x += k;
    if (x <= 5) al++;
  }
  printf("%d", al / 3);
  return 0;
}
