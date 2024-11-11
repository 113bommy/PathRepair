#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n == 0)
    puts("1");
  else
    printf("%d\n", 4 * int(sqrt(2) * (double)n));
}
