#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int n;
int p[MAXN], ones[MAXN << 1];
int main() {
  while (~scanf("%d", &n)) {
    long long sum = 0, mn;
    int mn_idx = 0, pos = 0, neg = 0;
    memset(ones, 0, sizeof(ones));
    for (int i = 1; i <= n; ++i) {
      scanf("%d", p + i);
      sum += ((p[i] - i) < 0 ? -(p[i] - i) : (p[i] - i));
      if (p[i] > i)
        ++pos;
      else
        ++neg;
      if (p[i] >= i) ++ones[p[i] - i];
    }
    mn = sum;
    for (int i = 1; i <= n; ++i) {
      sum = sum - pos + neg - 1;
      sum =
          sum -
          ((p[n - i + 1] - n) < 0 ? -(p[n - i + 1] - n) : (p[n - i + 1] - n)) +
          p[n - i + 1] - 1;
      if (p[n - i + 1] != 1) {
        ++pos;
        --neg;
      }
      pos -= ones[i];
      neg += ones[i];
      ++ones[p[n - i + 1] - 1 + i];
      if (sum < mn) {
        mn = sum;
        mn_idx = i;
      }
    }
    printf("%I64d %d\n", mn, mn_idx);
  }
}
