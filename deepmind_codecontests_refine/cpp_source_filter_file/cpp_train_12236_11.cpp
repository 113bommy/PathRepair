#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  int p = ((a + b) + n) % n;
  if (p == 0) p = n;
  printf("%d\n", p);
}
