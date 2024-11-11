#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, i = 0, l, r;
  cin >> n >> x;
  for (i = 1; i <= n - x; i++) printf("%d ", i);
  r = n;
  l = n - x + 1;
  while (l) {
    i++;
    if (l > r) break;
    if (i % 2)
      printf("%d ", r), r--;
    else
      printf("%d ", l), l++;
  }
  return 0;
}
