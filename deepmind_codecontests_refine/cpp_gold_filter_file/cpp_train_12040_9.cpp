#include <bits/stdc++.h>
using namespace std;
int n, ans;
vector<int> yy[200200];
int digit(int n) {
  int ans = 1;
  while (n) {
    if (n % 10 != 0) ans *= (n % 10);
    n /= 10;
  }
  return ans;
}
int rec(int n) {
  if (n < 10)
    return n;
  else
    return rec(digit(n));
}
int main() {
  int i, j;
  for (i = 1; i <= 1000000; i++) {
    yy[rec(i)].push_back(i);
  }
  while (scanf("%d", &n) != EOF) {
    while (n--) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      printf("%d\n", upper_bound(yy[x].begin(), yy[x].end(), r) -
                         lower_bound(yy[x].begin(), yy[x].end(), l));
    }
  }
}
