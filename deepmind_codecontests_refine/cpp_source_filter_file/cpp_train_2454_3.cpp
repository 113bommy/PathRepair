#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
  scanf("%d%d%d", &a, &b, &c);
  int ans = a;
  ans = min(a, b / 2);
  ans = min(a, c / 4);
  ans = ans * 7;
  printf("%d\n", ans);
  return 0;
}
