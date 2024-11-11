#include <bits/stdc++.h>
using namespace std;
const long long MX = 1e10;
const long long MD = 1e6;
int main() {
  int n, k, m, t;
  scanf("%d%d%d%d", &n, &k, &m, &t);
  int l = n, dc = k;
  while (t--) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == 0) {
      if (b < dc) {
        l -= b;
        dc -= b;
      } else {
        l -= l - b;
      }
    } else {
      l++;
      if (b <= k) {
        dc++;
      }
    }
    printf("%d %d\n", l, dc);
  }
  return 0;
}
