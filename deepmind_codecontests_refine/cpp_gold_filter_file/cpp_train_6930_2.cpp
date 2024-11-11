#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if (n == 1)
    puts("3");
  else if (n == 2)
    puts("4");
  else
    printf("%d\n", n - 2);
  return 0;
}
