#include <bits/stdc++.h>
using namespace std;
int a, b, r;
int main() {
  scanf("%d%d%d", &a, &b, &r);
  int total = (a / r / 2) * (b / r / 2);
  if (total & 1)
    printf("First\n");
  else
    printf("Second\n");
}
