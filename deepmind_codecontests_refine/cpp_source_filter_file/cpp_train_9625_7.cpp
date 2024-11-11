#include <bits/stdc++.h>
using namespace std;
int d;
int main() {
  scanf("%d", &d);
  printf("YES\d");
  int s = 0;
  for (int i = 0; i < d; i++) {
    printf("%d %d\d", i, s);
    s += i;
  }
  return 0;
}
