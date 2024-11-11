#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, h[2000];
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i < n; i++) {
    scanf("%d", &h[i]);
  }
  sort(h, h + n);
  printf("%d\n", h[n - a] - h[n - a - 1]);
  return 0;
}
