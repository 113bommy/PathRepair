#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, r;
  scanf("%d%d%d", &a, &b, &r);
  if (max(a, b) < 2 * r)
    printf("Second");
  else
    printf("First");
}
