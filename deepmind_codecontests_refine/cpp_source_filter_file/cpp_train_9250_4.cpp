#include <cstdio>
int main() {
  int n, k, x, y;
  scanf("%d%d%d%d", &n, &k, &x, &y);
  printf("%d\n",n>k ? (n-k) * y + k * x : n * x));
}