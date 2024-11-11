#include <bits/stdc++.h>
using namespace std;
int main() {
  int ct[10] = {2, 7, 2, 3, 3, 4, 1, 5, 1, 2};
  int n;
  scanf("%d", &n);
  int first = n / 10, second = n % 10;
  int ans = ct[first] * ct[second];
  printf("%d", ans);
  return 0;
}
