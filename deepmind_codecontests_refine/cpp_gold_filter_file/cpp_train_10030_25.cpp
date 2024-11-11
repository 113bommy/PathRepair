#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, r;
  scanf("%d %d %d", &a, &b, &r);
  if (2 * r > a || 2 * r > b)
    printf("Second");
  else
    printf("First");
  return 0;
}
