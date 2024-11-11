#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int now = 1;
  while (now < n) {
    if (now & 1)
      now = (now) + (1) + (now + 1);
    else
      now = (now) + (1) + (now);
  }
  if (now == n || now + 1 == n)
    printf("1\n");
  else
    printf("0\n");
  return 0;
}
