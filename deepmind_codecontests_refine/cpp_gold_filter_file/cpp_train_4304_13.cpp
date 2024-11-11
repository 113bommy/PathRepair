#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  scanf("%d", &n);
  int s = 0, nr = 0;
  s = 1;
  for (int i = 2; i <= n; i++) nr += 12, s += nr;
  printf("%d\n", s);
  return 0;
}
