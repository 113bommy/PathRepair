#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 20;
long long ans = 0;
int main() {
  long long n, q, p;
  scanf("%I64d%I64d", &n, &q);
  long long two[70] = {1};
  for (int i = (1); i < (63); ++i) two[i] = two[i - 1] * 2;
  while (q--) {
    scanf("%I64d", &p);
    if (p & 1) {
      printf("%I64d\n", (p + 1) / 2);
    } else {
      long long step = n - p / 2;
      int l = 0, r = 62, mid;
      while (l < r) {
        mid = l + ((r - l + 1) >> 1);
        if (step % two[mid] == 0) {
          l = mid;
        } else
          r = mid - 1;
      }
      p += step / two[l] * (two[l + 1] - 1);
      printf("%I64d\n", (p + 1) / 2);
    }
  }
  return 0;
}
