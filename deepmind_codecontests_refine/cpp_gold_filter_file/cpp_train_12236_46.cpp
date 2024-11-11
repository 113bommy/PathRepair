#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  int ret = (a + b + n) % n;
  while (ret <= 0) ret += n;
  printf("%d", ret);
  return 0;
}
